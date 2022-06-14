#include <bits/stdc++.h>
using namespace std;
int mcm(int mat[100], int brackets[100][100], int dp[100][100], int n)
{
    for(int i=1; i<n; i++)
    {
        dp[i][i]=0;
    }
    for(int i=n-1; i>=1; i--)
    {
        for(int j=i+1; j<=n-1; j++)
        {
            int miniSteps=INT_MAX;
            for(int k=i; k<=j-1; k++)
            {
                int steps=mat[i-1]*mat[k]*mat[j]+dp[i][k]+dp[k+1][j];
                if(miniSteps>steps)
                {
                    miniSteps=steps;
                    brackets[i][j]=k;
                }
            }
            dp[i][j]= miniSteps;
        }
    }
    return dp[1][n-1];
}
void parenthesis(int i, int j, int brackets[100][100], char &name)
{
    if(i==j)
    {
        cout<<name;
        name++;
        return;
    }
    cout<<"(";
    parenthesis(i,brackets[i][j],brackets,name);
    parenthesis(brackets[i][j]+1,j,brackets,name);
    cout<<")";
}
int main()
{
    cout<<"Enter the number of matrices: "<<endl;
    int n;
    cin>>n;
    n++;
    cout<<"Enter the matrices dimension: "<<endl;
    int brackets[100][100];
    int dp[100][100];
    int mat[100];
    for(int i=0; i<n; i++)
    {
        cin>>mat[i];
    }
    cout<<"MINIMUM OPERATION IS: "<<mcm(mat,brackets,dp,n)<<endl;
    cout<<"THE PATTEN WILL BE:  "<<endl;
    char name='A';
    parenthesis(1,n-1,brackets,name);
    cout<<endl;
    cout<<"M TABLE"<<endl;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"S TABLE"<<endl;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            cout<<brackets[i][j]<<"\t";
        }
        cout<<endl;
    }
 
   
    return 0;
}