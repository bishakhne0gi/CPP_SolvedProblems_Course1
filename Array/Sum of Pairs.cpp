#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    int n=arr.size();
    int upper=n-1, low=0, diff=INT_MAX, f_upper, f_low;
    while(low<upper){
        if(abs(arr[upper]+arr[low]-x)<diff){
            f_upper=upper;
            f_low=low;
            diff=abs(arr[upper]+arr[low]-x);
        }
        if(arr[upper]+arr[low]>x){
            upper--;
        }
        else{
            low++;
        }
    }
    return {arr[f_low],arr[f_upper]};
}