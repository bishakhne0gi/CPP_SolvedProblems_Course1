#include<bits/stdc++.h>
using namespace std;
int a[100];
int partition(int s, int e)
{
    int i=s-1;
    int pivot=a[e];
    for(int j=s; j<e; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[e]);
    return(i+1);
}
void quicksort(int s, int e)
{
    if(s>=e)
        return;
    int p=partition(s,e);
    quicksort(s,p-1);//left
    quicksort(p+1,e);//right
}
int main()
{
    cout<<"Enter the number of elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Input array elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(0, n-1);
    cout<<"Sorted array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}