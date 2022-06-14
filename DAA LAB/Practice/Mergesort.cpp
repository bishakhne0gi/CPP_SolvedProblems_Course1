#include<bits/stdc++.h>
using namespace std;
int a[100];
void merge(int s, int e)
{
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    int temp[100];
    int counter=0;
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
    int k=0;
    for(int idx=s; idx<=e; idx++)
    {
        a[idx]=temp[k];
        k++;
    }
    return;
}
void mergersort(int s, int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergersort(s,mid);
    mergersort(mid+1,e);
    return merge(s,e);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    mergersort(0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}