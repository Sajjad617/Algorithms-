#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n==0)
        return 1;
    int df = fact(n-1);
    return df * n;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    // int ans = fact(n);
    // cout << ans;
    // or
    int f = 1;
    for(int i=1; i<=n; i++)
    {
        f *= i;
    }
    cout << f <<endl;

    return 0;
}