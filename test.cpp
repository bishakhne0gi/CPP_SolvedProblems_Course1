#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define setBits(x) builin_popcount(x)
using namespace std;
int helper(int idx, vi &a, int n, int ans, vi &dp)
{
    if (idx >= n)
    {
        return 0;
    }

    int one = 0;
    int three = INT_MAX;

    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    if (idx + 1 < n)
    {
        one = (helper(idx + 1, a, n, ans, dp) + abs(a[idx + 1] - a[idx]));
    }

    if (idx + 3 < n)
    {

        three = helper(idx + 3, a, n, ans, dp) + abs(a[idx + 3] - a[idx]);
    }

    ans += min(one, three);

    dp[idx] = ans;
    return dp[idx];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vi dp(n + 1, -1);
        int idx = 0;
        int one = 0, three = 0;
        int res = 0;
        int ans = helper(idx, a, n, res, dp);

        cout << ans << endl;

        cout << endl;
    }
    return 0;
}