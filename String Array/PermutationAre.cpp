#include <bits/stdc++.h>
using namespace std;
 
bool arePermutation(string A, string B)
{
    int n1=A.length();
    int n2=B.length();
    if(n1!=n2){
        return false;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0; i<n1; i++){
        if(A[i]!=B[i]){
            return false;
        }
    }
    return true;
}