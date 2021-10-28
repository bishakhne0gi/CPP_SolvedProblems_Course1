#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> A, int Val) {
    int low=0, upper=A.size()-1;
    while(low<=upper){
        int mid=(low+upper)/2;
        if(A[mid]==Val){
            return A[mid];
        }
        else if(Val>A[mid]){
            low=mid+1;
        }
        else if(Val<A[mid]){
            upper=mid-1;
        }
    }
      if(A[upper]>Val){

        return A[upper-1];

    }