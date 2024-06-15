#include <vector>
#include <memory>
#include <utility>
#include <iostream>

using namespace std;

typedef struct
{
    int id;
    int color;
    int parent;
    int d;
    int f;

    vector<int> traversalOrder; // Store the order of visited vertices

} Vertex;

bool hasCycleUtil(const vector<vector<int>> &graph, int node, vector<bool> &visited, vector<bool> &recursionStack, vector<int> &cycleNodes)
{
    if (!visited[node])
    {
        visited[node] = true;
        recursionStack[node] = true;
        cycleNodes.push_back(node);

        for (int i = 0; i < graph.size(); ++i)
        {
            if (graph[node][i])
            {
                if (!visited[i] && hasCycleUtil(graph, i, visited, recursionStack, cycleNodes))
                {
                    return true;
                }
                else if (recursionStack[i])
                {
                    // Found a cycle, store the nodes forming the cycle
                    while (!cycleNodes.empty())
                    {
                        // cout << cycleNodes.back() << " ";
                        cycleNodes.pop_back();
                    }
                    // cout << i << endl;
                    return true;
                }
            }
        }
    }

    recursionStack[node] = false;
    cycleNodes.pop_back();
    return false;
}

bool hasCycle(const vector<vector<int>> &graph)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    vector<bool> recursionStack(numNodes, false);
    vector<int> cycleNodes;

    for (int i = 0; i < numNodes; ++i)
    {
        if (!visited[i])
        {
            if (hasCycleUtil(graph, i, visited, recursionStack, cycleNodes))
            {
                return true;
            }
        }
    }

    return false;
}

vector<vector<int>> transpose2DVector(const vector<vector<int>> &graph)
{
    int numNodes = graph.size();
    vector<vector<int>> transpose(numNodes, vector<int>(numNodes, 0));

    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            transpose[i][j] = graph[j][i];
        }
    }

    return transpose;
}

std::vector<std::vector<int>> matrix_to_adjacency_list(const std::vector<std::vector<int>> &matrix)
{
    std::vector<std::vector<int>> adjacency_list(matrix.size());

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == 1)
            {
                adjacency_list[i].push_back(j);
            }
        }
    }

    return adjacency_list;
}

void topologicSort(std::vector<Vertex> &u, std::vector<int> &compileOrder)
{
    for (size_t i = 0; i < u.size(); ++i)
    {
        for (size_t j = i + 1; j < u.size(); ++j)
        {
            if (u[j].f > u[i].f)
            {
                std::swap(u[i], u[j]);
            }
        }
    }

    for (size_t i = 0; i < u.size(); ++i)
    {
        compileOrder.push_back(u[i].id);
    }
}

void DFSVISIT(vector<vector<int>> G, vector<Vertex> &u, int i, int &time)
{
    time++;

    u[i].d = time;
    u[i].color = 1;

    for (int j = G[i].size() - 1; j >= 0; --j)
    {
        int neighborIndex = G[i][j];

        if (u[neighborIndex].color == 0)
        {
            u[neighborIndex].parent = i;
            DFSVISIT(G, u, neighborIndex, time);
        }
    }

    u[i].color = 2;
    time++;
    u[i].f = time;
}

// check if the vector has the element
bool checkConsist(vector<int> &visited, int &id)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == id)
            return true;
    }
    return false;
}

void DFSVISIT2(vector<vector<int>> G, vector<Vertex> &u, int i, vector<int> &visited, vector<int> &cycle)
{

    visited.push_back(i);
    for (int j = G[i].size() - 1; j >= 0; --j)
    {
        int neighborIndex = G[i][j];

        if (!checkConsist(visited, neighborIndex))
        {
            u[neighborIndex].parent = i;
            cycle.push_back(neighborIndex);
            DFSVISIT2(G, u, neighborIndex, visited, cycle);
        }
        else if (visited.back() == neighborIndex && u[neighborIndex].parent == -1)
        {
            cycle.push_back(neighborIndex);
        }
    }
}

void run(const std::vector<std::vector<int>> &dependencyMatrix,
         bool &isCompilable,
         std::vector<int> &compileOrder,
         std::vector<std::vector<int>> &cyclicDependencies)
{
    if (hasCycle(dependencyMatrix))
    {
        isCompilable = false;
        vector<Vertex> u;
        for (int i = 0; i < dependencyMatrix.size(); ++i)
        {
            Vertex v;
            v.id = i;
            v.color = 0; // 0 -> white 1 -> gray 2 -> black
            v.parent = -1;
            v.d = -1;
            v.f = -1;
            u.push_back(v);
        }

        int time = -1;
        for (int i = u.size() - 1; i >= 0; --i)
        {
            if (u[i].color == 0)
            {
                DFSVISIT(matrix_to_adjacency_list(dependencyMatrix), u, i, time);
            }
        }

        topologicSort(u, compileOrder);

        for (Vertex &v : u)
        {
            v.color = 0;
            v.parent = -1;
        }

        vector<int> visited;
        vector<int> cycle;
        vector<vector<int>> transpose = transpose2DVector(dependencyMatrix);

        for (int i = 0; i < u.size(); ++i)
        {
            time = -1;
            cycle.clear();
            cycle.push_back(u[i].id);
            DFSVISIT2(matrix_to_adjacency_list(transpose), u, u[i].id, visited, cycle);
            if (cycle.size() <= 1)
                continue;
            cyclicDependencies.insert(cyclicDependencies.begin(), cycle);
        }

        for (int i = 0; i < cyclicDependencies.size(); ++i)
        {
            if (cyclicDependencies[i].size() == 2 && cyclicDependencies[i][0] == cyclicDependencies[i][1])
            {
                cyclicDependencies[i].pop_back(); // self cycle case
            }
        }
    }
    else
    {
        isCompilable = true;
        vector<Vertex> u;
        for (int i = 0; i < dependencyMatrix.size(); ++i)
        {
            Vertex v;
            v.id = i;
            v.color = 0; // 0 -> white 1 -> gray 2 -> black
            v.parent = -1;
            v.d = -1;
            v.f = -1;
            u.push_back(v);
        }
        int time = -1;
        for (int i = u.size() - 1; i >= 0; --i)
        {
            if (u[i].color == 0)
            {
                DFSVISIT(matrix_to_adjacency_list(dependencyMatrix), u, i, time);
            }
        }

        topologicSort(u, compileOrder);
    }
}

int main()
{

    vector<vector<int>> g = {{0, 1},
                             {0, 0}};

    bool isCompilable;
    vector<int> compileOrder;
    vector<vector<int>> cyclicDependencies;

    run(g, isCompilable, compileOrder, cyclicDependencies);
    if (isCompilable)
    {
        cout << "Compilable" << endl;
        for (int i = 0; i < compileOrder.size(); ++i)
        {
            cout << compileOrder[i] << " ";
        }
    }

    cout << endl;

    for (int i = 0; i < cyclicDependencies.size(); ++i)
    {
        for (int j = 0; j < cyclicDependencies[i].size(); ++j)
        {
            cout << cyclicDependencies[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
