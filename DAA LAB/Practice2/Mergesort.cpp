#include<bits/stdc++.h>
using namespace std;
int a[100];
void merge(int s, int e)
{
    int temp[100];
    int k=0;
    int counter=0;
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    while(i<=m && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[counter]=a[i];
            i++;
            counter++;
        }
        else
        {
            temp[counter]=a[j];
            j++;
            counter++;
        }
    }
    while(i<=m)
    {
        temp[counter]=a[i];
            i++;
            counter++;
    }
    while(j<=e)
    {
        temp[counter]=a[j];
            j++;
            counter++;
    }
    for(int idx=s; idx<=e; idx++)
    {
        a[idx]=temp[k];
        k++;
    }
    return;
}
void mergesort(int s, int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergesort(s,mid);
    mergesort(mid+1,e);
    return merge(s,e);
}
int main()
{
    cout<<"Enter the no. of elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Input the array elements: "<<endl;
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
    mergesort(0,n-1);
     cout<<"Sorted array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}