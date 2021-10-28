#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v){
    int n=v.size();
    bool swapped;
    for(int times=0; times<n-1; times++){
        for(int j=0; j<n-times-1; j++){
            if(v[j]>v[j+1]){
                
                swap(v[j], v[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
        break;
        }
    
    }
    return v;

}