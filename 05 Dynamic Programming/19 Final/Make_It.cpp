#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int n;
bool find_value(int op1)
{
    if (op1 == n)
    {
        return true;
    }
    else if (op1 > n)
        return false;

    if (dp[op1] != -1)
        return dp[op1];
    return dp[op1] = find_value(op1 + 3) || find_value(op1 * 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        int op1 = 1;
        if (find_value(op1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}