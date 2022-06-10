/*
    TC: O(n2)
    SC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y)
{
    //column
    for(int k=0; k<x; k++)
    {
        if(board[k][y]==1)
        {
            return false;
        }
    }
    //Left Diagonal
    int i=x;
    int j=y;
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }
    //Right Diagonal
    i=x;
    j=y;
    while(i>=0 && j<n)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
void printBoard(int n, int board[][20])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool solveNQueen(int n, int board[][20], int i)
{
    //base case
    if(i==n)
    {
        printBoard(n,board);
        return true;
    }
    //recursive case
    for(int j=0; j<n; j++)
    {
        //whether current i,j is safe or not
        if(canPlace(board,n,i,j))
        {
            board[i][j]=1;
            bool success = solveNQueen(n,board,i+1);
            if(success==true)
            {
                return true;
            }
            //backtrack
            board[i][j]=0;
        }
    }
    return false;
}
int main()
{
    int board[20][20]={0};
    cout<<"Enter the value of n: "<<endl;
    int n;
    cin>>n;
    solveNQueen(n,board,0);
    return 0;
}