#include <bits/stdc++.h>
using namespace std;
int power(int a, int n){
    if(n==0)
        return 1;
    int subProb= power(a,n/2);
    int subProbSq = subProb*subProb;
    if(n&1)
        return a*subProbSq;
    return subProbSq;
}
int main(){
    cout<<power(2,3);
    return 0;
}