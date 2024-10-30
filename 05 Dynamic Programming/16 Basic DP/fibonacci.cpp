#include<bits/stdc++.h>
using namespace std;
const long long int N = 1e6+5;
long long int dp[N];
long long int fibo(int n)
{
    if(n == 0 || n == 1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    long long int ans = fibo(n-1)+fibo(n-2);
    dp[n] = ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;
    return 0;
}