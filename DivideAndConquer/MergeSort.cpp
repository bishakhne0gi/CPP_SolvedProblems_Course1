#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr, int s, int e)
{
    int i=s;
    int m=(s+e)/2;
    int j= m + 1;
    vector<int> temp;
    while(i<=m and j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        
        }
        
    }
    while(i<=m)
    {
        temp.push_back(arr[i++]);
    }
    while(j<=e)
    {
        temp.push_back(arr[j++]);
    }
    int k=0;
    for(int idx=s; idx<=e; idx++)
    {
        arr[idx]=temp[k++];
    }

}
void mergeSort(vector<int>&arr, int s, int e)
{
    //base case
    if(s>=e)
        return;
    //recursive case
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    return merge(arr, s, e);
}
int main()
{
    vector<int> arr;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int ele;
    for(int i=0;i<n;i++)
    {
        
        cin>>ele;
        arr.push_back(ele);
    
    }
    cout<<endl;
    cout<<"Unsorted Array"<<endl;
    for(int i=0; i<n; i++)
    {   
        cout<<arr[i]<<" , ";

    }
    cout<<endl;
    cout<<"Sorted Array"<<endl;
    mergeSort(arr,0,n);
    for(int i=0; i<n; i++)
    {   
        cout<<arr[i]<<", ";

    }
    cout<<endl;
    return 0;
}