#include <bits/stdc++.h>
using namespace std;
int a[100];
int maxi, mini;
void maxmin(int left, int right)
{
    int temp_maxi, temp_mini;
    if(left==right)
    {
        maxi=mini=a[left];
    }
    else if(right-left==1)
    {
        if(a[left]<=a[right])
        {
            mini=a[left];
            maxi=a[right];
        }
        else
        {
            mini=a[right];
            maxi=a[left];
        }
    }
    else
    {
        int mid=(left+right)/2;
        maxmin(left,mid);
        temp_maxi=maxi;
        temp_mini=mini;
        maxmin(mid+1,right);
        if(temp_maxi>maxi)
        {
            maxi=temp_maxi;
        }
        if(temp_mini<mini)
        {
            mini=temp_mini;
        }
    }
    return;
}
int main()
{
    cout<<"Enter the no. of elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Array inputs: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Array is: "<<endl;
    for(int i=0; i<n; i++)
    {
       cout<<a[i]<<" ";
    }
    cout<<endl;
    maxi=a[0], mini=a[0];
    maxmin(0,n-1);
    cout<<"Maximum: "<<maxi<<endl;
    cout<<"Minimum: "<<mini<<endl;
    return 0;
}