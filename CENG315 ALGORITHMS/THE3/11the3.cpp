//#include "the3.h"
#include <iostream>
#include <limits>

int max3(int number1,int number2, int number3)
{
    if (number1 >= number2) 
    {
        if (number1 >= number3) 
        {
            return number1;
        }
        else 
        {
            return number3;
        }
    }
    else {
        if (number2 >= number3) 
        {
            return number2;
        }
        else 
        {
            return number3;
        }
    }
}
int max2(int number1,int number2)
{
    if (number1 >= number2) 
    {
        return number1;
    }
    else
    {
        return number2;
    }
}


int myrecursive(std::string sequence_A, std::string sequence_B,int locA, int locB, int gap, int mismatch, int match, std::string &possible_alignment, int& call_count,int& highest_alignment_score)
{
    if(locA==0 || locB==0)
    {
        return 0;
    }
    else
    {
        int ara;
        if(sequence_A[locA-1]==sequence_B[locB-1])
        {
            ara=match;
        }
        else
        {
            ara=-mismatch;
        }
        call_count=call_count+3;
        if(call_count>=1000000)
        {
            possible_alignment="STACK LIMIT REACHED";
            return INT_MIN;
        }
        return max3(
                    myrecursive( sequence_A,sequence_B, locA-1,locB-1, gap, mismatch,  match,possible_alignment, call_count,highest_alignment_score)+ara,
                    myrecursive( sequence_A,sequence_B, locA,locB-1, gap, mismatch,  match,possible_alignment, call_count,highest_alignment_score)-gap,
                    myrecursive( sequence_A,sequence_B, locA-1,locB, gap, mismatch,  match,possible_alignment, call_count,highest_alignment_score)-gap
                    );
    }


}
int recursive_alignment(std::string sequence_A, std::string sequence_B, int gap, int mismatch, int match, std::string &possible_alignment, int call_count){
    int highest_alignment_score;
    int size_A=sequence_A.size();
    int size_B=sequence_B.size();
    
    return myrecursive(sequence_A,sequence_B,size_A,size_B,gap,mismatch,match,possible_alignment,call_count,highest_alignment_score);
       
}


int dp_table_alignment(std::string sequence_A, std::string sequence_B, int gap, int mismatch, int match, std::string &possible_alignment){
    int highest_alignment_score;
    int size_A=sequence_A.size();
    int size_B=sequence_B.size();
    int arr[size_B+1][size_A+1];
    for(int i=0;i<=size_A;i++)
    {
        arr[0][i]=0;
    }
    for(int i=0;i<=size_B;i++)
    {
        arr[i][0]=0;
    }
    
    
    for(int i=1;i<size_B+1;i++)
    {
        for(int j=1;j<size_A+1;j++)
        {
            
            if(sequence_A[j-1]==sequence_B[i-1])
            {
                arr[i][j]=arr[i-1][j-1]+match;
            }
            else
            {
                int ara2=max2(arr[i-1][j]-gap,arr[i][j-1]-gap);
                arr[i][j]=ara2;
            } 
        }
    }
    int i=size_B;
    int j=size_A;
    possible_alignment="";
    while (i > 0 && j > 0) 
    {
        if(sequence_A[j-1]==sequence_B[i-1])
        {
            possible_alignment=sequence_A[j-1]+possible_alignment;
            i--;
            j--;
        }
        else if (arr[i - 1][j] > arr[i][j - 1])
        {
            possible_alignment="_"+possible_alignment;
            i--;
        }
        else
        {
            possible_alignment="."+possible_alignment;
            j--;
        }
        
    }
    while(i>0)
    {
        possible_alignment="_"+possible_alignment;
        i--;
    }
    while(j>0)
    {
        possible_alignment="."+possible_alignment;
        j--;
    }

    highest_alignment_score=arr[size_B][size_A];
    return highest_alignment_score;    
}


int main()
{
    int gap=1;
    int mismatch=2;
    int match=4;
    int call_count=0;
    std::string stringA="THY";
    std::string stringB="BETH";
    std::string possiblealignment;
    int returnval=dp_table_alignment(stringA,stringB,gap,mismatch,match,possiblealignment);
    int returnval1=recursive_alignment(stringA,stringB,gap,mismatch,match,possiblealignment,call_count);
    return 0;
}