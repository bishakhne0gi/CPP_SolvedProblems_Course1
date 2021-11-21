#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int current = arr[i];
        int prev= i -1;
        while(prev>=0 and arr[prev]>current)
        {
            arr[prev+1]=arr[prev];
            prev=prev-1;
        }
        arr[prev+1]=current;
    }
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
    insertionSort(arr,n);
    for(int i=0; i<n; i++)
    {   
        cout<<arr[i]<<", ";

    }
    cout<<endl;
    return 0;
}