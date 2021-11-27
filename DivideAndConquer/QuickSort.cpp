#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr, int s, int e)
{
    int i = s-1;
    int pivot=arr[e];
    for(int j=s; j<e; j++)
    {
        if(arr[j]< pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;

}
void quickSort(vector<int>&arr, int s, int e)
{
    //Base Case
    if(s>=e)
        return;
    //Recursive Case
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
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
    quickSort(arr,0,n);
    for(int i=0; i<n; i++)
    {   
        cout<<arr[i]<<", ";

    }
    cout<<endl;
    return 0;
}