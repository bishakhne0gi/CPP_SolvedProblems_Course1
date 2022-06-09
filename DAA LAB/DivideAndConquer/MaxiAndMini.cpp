/*
    If the array is sorted
    TC: O(log n)
    SC: o(n) stack space will be needed

    If the array is not sorted
    TC: O(n)
    SC: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
int maxi, mini;
int a[100];
void maximini(int left, int right)
{
    int temp_maxi, temp_mini, mid;
    if (left == right)
    {
        maxi = mini = a[left];
    }
    else
    {
        if (right - left == 1)
        {
            if (a[left] < a[right])
            {
                mini = a[left];
                maxi = a[right];
            }
            else
            {
                mini = a[right];
                maxi = a[left];
            }
        }
        else
        {
            mid = (left + right) / 2;
            maximini(left, mid);
            temp_maxi = maxi;
            temp_mini = mini;
            maximini(mid + 1, right);
            if (temp_maxi > maxi)
                maxi = temp_maxi;
            if (temp_mini < mini)
                mini = temp_mini;
        }
    }
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
    maxi = a[0];
    mini = a[0];
    maximini(0, n - 1);
    cout << "MINIMUM: " << mini << endl;
    cout << "MAXIMUM: " << maxi << endl;
    return 0;
}