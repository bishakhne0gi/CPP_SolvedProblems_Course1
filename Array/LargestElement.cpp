#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    int i;
    int maxum = arr[0];
    for (i = 1; i < arr.size(); i++)
            maxum= max(maxum, arr[i]);
 
    return maxum;
}