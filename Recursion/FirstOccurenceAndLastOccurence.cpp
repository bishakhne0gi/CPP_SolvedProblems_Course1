#include <bits/stdc++.h>
using namespace std;
int firstOccur(int *arr, int n, int key){
    //base case
    if(n==0)
        return -1;
    //recursive call
    if(arr[0]==key)
        return 0;
    int subIndex= firstOccur(arr+1, n-1, key);
    if(subIndex!=-1)
        return subIndex+1;
    return -1;
}
int lastOccur(int *arr, int n, int key){
    //base case
    if(n==0)
        return -1;
    //recursive call
    int subIndex= lastOccur(arr+1, n-1, key);
    if(subIndex==-1){
        if(arr[0]== key)
            return 0;
        else
            return -1;
        
    }
    else{
        return subIndex+1;
    }
}
int main(){
    int arr[]={1,2,3,4,3,5};
    int n= sizeof(arr)/sizeof(n);
    cout<<firstOccur(arr,n,9);
    cout<<endl;
    cout<<lastOccur(arr,n,3);

    return 0;
}