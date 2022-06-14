/*
    TC:
    Worst case when the array is sorted: o(n2)
    Best case: O(n logn)
    SC:  O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
int partition(int s, int e)
{
    int i = s - 1;
    int pivot = a[e];
    for (int j = s; j < e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}
void quicksort(int s, int e, int n)
{
    if (s >= e)
        return;
    int p = partition(s, e);
    cout<<"Steps: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    quicksort(s, p - 1,n); // left
    quicksort(p + 1, e,n); // right
}
int main()
{
    cout << "Enter the number of elements: " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    quicksort(0, n-1, n);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    return 0;
}