#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr, int n)
{
    for(int pos=0; pos< n-1; pos++)
    {
        int min_pos = pos;
        int current=arr[pos];
        for(int j=pos; j<n; j++){
            if(arr[j]<arr[min_pos])
            
                min_pos=j;
        }
        swap(arr[min_pos],arr[pos]);
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
    selectionSort(arr,n);
    for(int i=0; i<n; i++)
    {   
        cout<<arr[i]<<", ";

    }
    cout<<endl;
    return 0;
}