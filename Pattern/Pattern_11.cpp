#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define setBits(x) builin_popcount(x)
using namespace std;
void helper(int n)
{
    for (int i = 1; i <= n; i++)
    {

        if (i & 1 == 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j & 1 != 0)
                    cout << "0 ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 1; j <= i; j++)
            {
                if (j & 1 != 0)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    helper(n);
    return 0;
}