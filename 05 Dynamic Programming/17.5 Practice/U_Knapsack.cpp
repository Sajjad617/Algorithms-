#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];


int knapsack(int n, int cost[], int value[], int c)
{
    if(n==0 || c==0) return 0;

    if(dp[n][c] != -1)
    {
        return dp[n][c];
    }
    // cout << "###" << endl;
        
    if(value[n-1] <= c)
    { 
        int op1 = knapsack(n-1, cost, value, c-value[n-1])+cost[n-1];
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
    int n, c;
    cin >> n >> c;
    int value[n];
    int cost[n];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        value[i] = a;
        cost[i] = b;
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=c; j++)
        {
            dp[i][j] = -1;
        }
    }
    // cout << n << " "  << c << endl;
    int totalcost = knapsack(n, cost, value, c);

    cout << totalcost << endl;
    // cout << "###" << endl;

    return 0;
}