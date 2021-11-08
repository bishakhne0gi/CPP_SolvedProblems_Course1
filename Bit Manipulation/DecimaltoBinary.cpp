#include <bits/stdc++.h>
using namespace std;
int decToBinary(int n){
    int ans=0;
    int p=1;
    while(n>0){
        int last_bit=n&1;
        ans+=p*last_bit;
        p*=10;
        n=n>>1;
    }
    return ans;
}
int main(){
    cout<<"Enter the number: "<<endl;
    int n;
    cin>>n;
    cout<<decToBinary(n)<<endl;
    return 0;
}