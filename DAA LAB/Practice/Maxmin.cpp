#include <bits/stdc++.h>
using namespace std;
int a[100];
int maxi,mini;
void maxmin(int a[], int left, int right)
{
    int temp_maxi, temp_mini;
    if(left==right)
        maxi=mini=a[left];
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
        maxmin(a,left,mid);
        temp_maxi=maxi;
        temp_mini=mini;
        maxmin(a,mid+1,right);
        if(temp_mini<mini)
            mini=temp_mini;
        if(temp_maxi>maxi)
            maxi=temp_maxi;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    maxi=a[0];
    mini=a[0];
    maxmin(a,0,n-1);
    cout<<"MAX: "<<maxi<<endl;
    cout<<"MIN: "<<mini<<endl;
    return 0;
}