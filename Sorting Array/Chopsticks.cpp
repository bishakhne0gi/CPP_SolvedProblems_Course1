#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    sort(length.begin(),length.end());
    int result=0;
    for(int i=0; i<length.size()-1; i++){
        if(length[i+1]-length[i]<=D){
            result++;
            i++;
        }
    }
    return result;
}