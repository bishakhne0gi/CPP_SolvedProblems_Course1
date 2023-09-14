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
    int counter=(n*2)-1;
    for(int i=n; i>0; i--)
    {
        for(int j=n; j>i; j--)
        {
            cout<<" ";
        }
        for(int k=1; k<=counter; k++)
        {
            cout<<"*";
        }
        counter=counter-2;
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