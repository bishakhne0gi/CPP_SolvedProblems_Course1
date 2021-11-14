#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    if((n & (n-1))==0)
        cout<<"Power of two"<<endl;
    else
        cout<<"Not Power of two "<<endl;
    return 0;
}