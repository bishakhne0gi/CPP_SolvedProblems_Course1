#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define setBits(x) builin_popcount(x)
using namespace std;
//memoisation
/*
int fibonaaci(int n, vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonaaci(n-1, dp)+ fibonaaci(n-2, dp);
}
*/
//optimised solution
int main()
{
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;
    for(int i=2; i<=n; i++)
    {
        int curr= prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
    // cout<<fibonaaci(n,dp);
    return 0;
}