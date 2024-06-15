#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "parser.h"

void exe_subshell(char *subshell);
void exe_command(command *cmd);
void exe_pipe_general(pipeline *pipe_);
void execute_parallel(parsed_input *input);
// int check_subshell(parsed_input *input);       // Check if input is a subshell
void pipe_helper(parsed_input *input); // Helper function for executing pipelines
void para_helper(parsed_input *input); // Helper function for executing parallel commands

int check_subshell(parsed_input *input)
{
    for (int i = 0; i < input->num_inputs; i++)
    {
        if (input->inputs[i].type == INPUT_TYPE_SUBSHELL)
            return 1;
    }
    return 0;
}

void exe_seq(parsed_input *input)
{
    int num_inputs = input->num_inputs;
    for (int i = 0; i < num_inputs; ++i)
    {
        switch (input->inputs[i].type)
        {
        case INPUT_TYPE_COMMAND:
            exe_command(&input->inputs[i].data.cmd);
            break;
        case INPUT_TYPE_PIPELINE:
            exe_pipe_general(&input->inputs[i].data.pline);
            break;
        default:
            fprintf(stderr, "error\n");
            break;
        }
    }
}

void exe_command(command *cmd)
{
    pid_t pid = fork();

    if (pid == 0) // child process
    {
        execvp(cmd->args[0], cmd->args);
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}

void exe_subshell(char *subshell)
{
    // Parse the subshell input to get the commands or pipelines inside
    parsed_input subshell_input;
    parse_line(subshell, &subshell_input);
    // fork a child process for the subshell
    pid_t pid = fork();

    if (pid == 0) // Child process
    {
        command *cmd;
        switch (subshell_input.separator)
        {
        case SEPARATOR_NONE:
            cmd = &subshell_input.inputs[0].data.cmd;
            execvp(cmd->args[0], cmd->args);
            break;
        case SEPARATOR_PIPE:
            pipe_helper(&subshell_input);
            break;
        case SEPARATOR_SEQ:
            exe_seq(&subshell_input);
            break;
        case SEPARATOR_PARA:
            para_helper(&subshell_input);
            break;
        default:
            fprintf(stderr, "subshell seperator error\n");
            break;
        }
        exit(EXIT_SUCCESS);
    }
    else // Parent process
    {
        waitpid(pid, NULL, 0);
    }
    free_parsed_input(&subshell_input);
}
void para_helper(parsed_input *input)
{
    int n = input->num_inputs;
    pid_t pids[n];

    // for n commands, n pipes to distribute the input to each command
    int pipes[n][2]; // 0 read, 1 write

    // Create pipes for inps
    for (int i = 0; i < n; ++i)
    {
        if (pipe(pipes[i]) == -1) // create N pipes
        {
            perror("pipe error handler");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            dup2(pipes[i][0], STDIN_FILENO); // Redirect stdin to current pipe read end

            for (int i = 0; i < n; i++)
            {
                close(pipes[i][0]); // Close read end of pipe
                close(pipes[i][1]); // Close write end of pipe (not needed by child processes)
            }

            if (input->inputs[i].type == INPUT_TYPE_PIPELINE)
            {
                exe_pipe_general(&input->inputs[i].data.pline);
            }
            else
            {
                execvp(input->inputs[i].data.cmd.args[0], input->inputs[i].data.cmd.args);
                // perror("execvp");
                // exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }
        else
        {
            pids[i] = pid; // store child's pid
        }
    }
    // repeater code
    pid_t rep_pid = fork();

    if (rep_pid == 0)
    {
        std::string input;
        char buffer[INPUT_BUFFER_SIZE * n]; //
        ssize_t bytesRead;
        input.clear();
        while ((bytesRead = read(STDIN_FILENO, buffer, INPUT_BUFFER_SIZE)) > 0)
        {
            input.append(buffer, bytesRead);
        }
        for (int i = 0; i < n; ++i)
        {
            write(pipes[i][1], input.c_str(), input.size());
        }

        for (int i = 0; i < n; ++i)
        {
            close(pipes[i][1]);
            close(pipes[i][0]);
        }
        exit(EXIT_SUCCESS);
    }


    for (int i = 0; i < n; ++i)
    {
        close(pipes[i][1]);
        close(pipes[i][0]);
    }

    for (int i = 0; i < n; ++i)
    {
        waitpid(pids[i], NULL, 0); // reap child processes in parallel
    }
    waitpid(rep_pid, NULL, 0); // reap repeater process
}

// execute internal pipelines
void exe_pipe_general(pipeline *pipe_)
{
    int num_commands = pipe_->num_commands;
    int pipes[num_commands - 1][2]; // One less pipe than the number of commands

    // Create pipes for commands
    for (int i = 0; i < num_commands - 1; ++i)
    {
        if (pipe(pipes[i]) == -1) // create N-1 pipes
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid[num_commands];

    // Execute commands in the pipeline
    for (int i = 0; i < num_commands; ++i)
    {
        pid[i] = fork();
        // redirect the input of the command or the first command in the pipeline to one the pipes created above
        if (pid[i] == 0) // Child process
        {
            // Connect pipes
            if (i > 0)
            {
                dup2(pipes[i - 1][0], STDIN_FILENO); // Redirect stdin to previous pipe read end
                close(pipes[i - 1][1]);              // Close unused write end of previous pipe
            }
            if (i < num_commands - 1)
            {
                dup2(pipes[i][1], STDOUT_FILENO); // Redirect stdout to current pipe write end
                close(pipes[i][0]);               // Close unused read end of current pipe
            }

            // Close all pipe ends
            for (int j = 0; j < num_commands - 1; ++j)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            // Execute cs command
            execvp(pipe_->commands[i].args[0], pipe_->commands[i].args);
        }
    }

    // Close all pipes in parent process
    for (int i = 0; i < num_commands - 1; ++i)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_commands; ++i)
    {
        waitpid(pid[i], NULL, 0);
    }
}

void pipe_helper(parsed_input *input)
{
    int n = input->num_inputs;
    int pipes[n - 1][2]; // One less pipe than the number of inps

    // Create pipes for inps
    for (int i = 0; i < n - 1; ++i)
    {
        if (pipe(pipes[i]) == -1) // create N-1 pipes
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid[n];

    for (int i = 0; i < n; ++i)
    {

        pid[i] = fork(); // fork CS processes

        // redirect the input of the command or the first command in the pipeline to one the pipes created above
        if (pid[i] == 0) // Child process
        {

            if (i > 0)
            {
                dup2(pipes[i - 1][0], STDIN_FILENO); // Redirect stdin to previous pipe read end
                close(pipes[i - 1][1]);              // Close unused write end of previous pipe
            }
            if (i < n - 1)
            {
                dup2(pipes[i][1], STDOUT_FILENO); // Redirect stdout to current pipe write end
                close(pipes[i][0]);               // Close unused read end of current pipe
            }

            // Close all pipe ends
            for (int j = 0; j < n - 1; ++j)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            if (input->inputs[i].type == INPUT_TYPE_SUBSHELL)
            {
                exe_subshell(input->inputs[i].data.subshell);
                exit(1);
            }

            if (input->inputs[i].type != INPUT_TYPE_SUBSHELL)
            {
                execvp(input->inputs[i].data.cmd.args[0], input->inputs[i].data.cmd.args);
            }

            // exit(EXIT_SUCCESS);
        }
    }

    // Close all pipes in parent process
    for (int i = 0; i < n - 1; ++i)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all child processes to finish
    for (int i = 0; i < n; ++i)
    {
        waitpid(pid[i], NULL, 0);
    }
}

void execute_parallel(parsed_input *input)
{
    int num_inputs = input->num_inputs;
    pid_t pids[num_inputs];

    // Execute each input in parallel
    for (int i = 0; i < num_inputs; ++i)
    {
        pid_t pid = fork(); // fork for each command

        if (pid == 0) // Child process
        {
            SINGLE_INPUT_TYPE inp_type = input->inputs[i].type;
            command *cmd;
            switch (inp_type)
            {
            case INPUT_TYPE_COMMAND:
                cmd = &input->inputs[i].data.cmd;
                execvp(cmd->args[0], cmd->args);
                break;
            case INPUT_TYPE_PIPELINE:
                exe_pipe_general(&input->inputs[i].data.pline);
                exit(EXIT_SUCCESS);
                break;
            default:
                fprintf(stderr, "error\n");
                exit(EXIT_FAILURE);
                break;
            }
        }
        else // Parent process
        {
            pids[i] = pid;
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_inputs; ++i)
    {
        waitpid(pids[i], NULL, 0);
    }
}

int main()
{
    parsed_input input;
    char buffer[INPUT_BUFFER_SIZE];

    while (1)
    {
        printf("/> ");
        fflush(stdout);

        // error handling for fgets
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            break;
        }

        // Remove newline char
        buffer[strcspn(buffer, "\n")] = '\0';

        // Parse the input line, if it is not valid, print error
        if (!parse_line(buffer, &input))
        {
            fprintf(stderr, "error\n");
            continue;
        }

        // check if buffer == quit
        if (strcmp(buffer, "quit") == 0)
        {
            break;
        }

        // pretty_print(&input);

        switch (input.separator)
        {
        case SEPARATOR_NONE:
            if (check_subshell(&input))
            {
                exe_subshell(input.inputs[0].data.subshell);
            }
            else
            {
                exe_command(&input.inputs[0].data.cmd);
            }
            break;
        case SEPARATOR_PIPE:
            pipe_helper(&input);
            break;
        case SEPARATOR_SEQ:
            exe_seq(&input);
            break;
        case SEPARATOR_PARA:
            execute_parallel(&input);
            break;
        default:
            fprintf(stderr, "error\n");
        }
        free_parsed_input(&input);
    }

    return 0;
}