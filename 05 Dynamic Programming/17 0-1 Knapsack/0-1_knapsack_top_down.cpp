#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int knapsack(int n, int cost[], int value[], int c)
{
    if(n==0 || c==0) return 0;
    if(dp[n][c] != -1)
    {
        return dp[n][c];
    }
    if(cost[n-1] <= c)
    {
        int op1 = knapsack(n-1, cost, value, c-cost[n-1])+value[n-1];
        int op2 = knapsack(n-1, cost, value, c);
        return dp[n][c] = max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n-1, cost, value, c);
        return dp[n][c] = op2;

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int cost[n], value[n];
    for(int i=0; i<n; i++)
    {
        cin >> cost[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> value[i];
    }
    int c;
    cin >> c;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<c; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, cost, value, c) << endl;
    return 0;
}