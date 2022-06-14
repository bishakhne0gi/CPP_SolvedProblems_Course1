#include <bits/stdc++.h>
using namespace std;
int a[100];
void swapc(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void heapify(int a[], int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
    {
        largest=left;
    }
    if(right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swapc(a[largest], a[i]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[], int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1; i>=0; i--)
    {
        swapc(a[i],a[0]);
        heapify(a,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    heapsort(a,n);
    cout<<"Sorted: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}