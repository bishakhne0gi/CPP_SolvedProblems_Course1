#include <bits/stdc++.h>
using namespace std;
int decrease(int n){
    //base case
    if(n==0)
        return 0;
    //towards the base
    cout<<n<<", ";
    decrease(n-1);
}
int increase(int n){
    //base case
    if(n==0)
        return 0;
    //towards the problem
    increase(n-1);
    cout<<n<<", ";
}
int main(){
    int n;
    cin>>n;
    decrease(n);
    cout<<endl;
    increase(n);
    return 0;
}