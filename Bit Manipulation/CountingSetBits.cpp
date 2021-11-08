#include <bits/stdc++.h>
using namespace std;
//0(n)
int countSetBits(int n){
    int ans=0;
    while(n>0){
        int last_bit=n&1;
        ans+=last_bit;
        n=n>>1;
    }
    return ans;
}
//0(number of seet bits) Faster Method
int hack_countSetBits(int n){
    int ans=0;
    while (n>0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<countSetBits(n)<<endl;
    cout<<hack_countSetBits(n)<<endl;
    return 0;
}