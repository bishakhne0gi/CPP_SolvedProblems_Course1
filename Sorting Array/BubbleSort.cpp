#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    for(int times=1; times<=n-1; times++)
    {
        //repeated swapping
        for(int j=0; j<=n-times-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
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
    bubbleSort(arr,n);
    for(int i=0; i<n; i++)
    {   
        cout<<arr[i]<<", ";

    }
    cout<<endl;
    return 0;
}