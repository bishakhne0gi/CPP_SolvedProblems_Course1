/*
    TC: O(n log n)
    SC: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int arr[100];
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        cout << "Steps: " << endl;
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << "  ";
        }
        cout << endl;
        heapify(arr, i, 0);
    }
}
int main()
{
    cout << "Enter the number of elements: " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Unsorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    heapsort(arr, n);
    cout<<endl;
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}