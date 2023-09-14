#include <bits/stdc++.h>
using namespace std;
int lowerbound(vector<int> a, int key)
{
    int s=0;
    int e=a.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int upperbound(vector<int> a, int key)
{
    int s=0;
    int e=a.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            s=mid+1;
        }
        else if(a[mid]<key)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> a={1,1,2,2,3,3,3,3,4,4};
    int lb=lowerbound(a,3);
    int ub=upperbound(a,3); 
    cout<<"Frequency is: "<<endl;
    cout<<(ub-lb)+1<<endl;
    return 0;
}