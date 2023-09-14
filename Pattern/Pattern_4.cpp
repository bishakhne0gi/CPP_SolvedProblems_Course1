#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define setBits(x) builin_popcount(x)
using namespace std;
void helper(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    helper(n);
    return 0;
}