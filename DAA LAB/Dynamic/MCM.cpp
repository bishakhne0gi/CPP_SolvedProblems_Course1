/*
    TC: O(n3)
    SC: O(n2)
*/
#include <bits/stdc++.h>
using namespace std;
int mCm(int mat[100], int brackets[][100], int dp[][100], int n)
{
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int miniSteps = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = mat[i - 1] * mat[k] * mat[j] + dp[i][k] + dp[k + 1][j];
                if (miniSteps > steps)
                {
                    miniSteps = steps;
                    brackets[i][j] = k;
                }
            }
            dp[i][j] = miniSteps;
        }
    }
    return dp[1][n - 1];
}

void print_optimal_parenthesis(int i, int j, int brackets[][100], char &name)
{
    if (i == j)
    {
        cout << name;
        name++;
        return;
    }
    cout << "(";

    print_optimal_parenthesis(i, brackets[i][j], brackets, name);
    print_optimal_parenthesis(brackets[i][j] + 1, j, brackets, name);
    cout << ")";
}
int main()
{

    cout << "Enter the number of matrices : ";
    int n;
    cin >> n;
    n++;
    cout << '\n';
    cout << "Enter the dimentions of matrices : ";
    int mat[100];
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    int dp[100][100];
    int brackets[100][100];
    int res = mCm(mat, brackets, dp, n);
    char name = 'A';
    cout <<endl;
    cout << "multiplication pattern will be: "<<endl;
    print_optimal_parenthesis(1, n - 1, brackets, name);
    cout<< "number of operations needed for this matrix multiplications are : "<<res<<endl;
    cout<<"M table"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"S table"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<brackets[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}