#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    while (n>0)
    {
        n=n&(n-1);
        ans++;
    }
    cout<<"Ans: "<<ans<<endl;
}