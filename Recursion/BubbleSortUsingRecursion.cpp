#include <bits/stdc++.h>
using namespace std;
void bubblesort(int a[], int n, int j){
    //base case
    if(n==0)
        return;
    if(j==n-1)
    {
        bubblesort(a,n-1,0);
        return;
    }
    if(a[j]>a[j+1])
        swap(a[j], a[j+1]);
    bubblesort(a, n, j+1);
}
int main(){
    int arr[]={3,6,7,2,1};
    int n= sizeof(arr)/sizeof(int);
    bubblesort(arr,n,0);
    for(auto x:arr){
        cout<<x<<", ";
    }
    return 0;
}