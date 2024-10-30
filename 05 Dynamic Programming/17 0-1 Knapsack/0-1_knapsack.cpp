#include<bits/stdc++.h>
using namespace std;
int knapsack(int n, int weight[], int value[], int w)
{
    if(n==0 || w==0) return 0;

    if(weight[n-1] <= w)
    {
        // duita option
        // op1 niye dekhbo, op2 na niye dekhbo

        int op1 = knapsack(n-1, weight, value, w-weight[n-1]+value[n-1]);
        int op2 = knapsack(n-1, weight, value, w);

        return max(op1, op2);
    }
    else
    {
        // ekta option
        // na niye dekhbo
        int op2 = knapsack(n-1, weight, value, w);
        return op2;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int weight[n], value[n];
    for(int i=0; i<n; i++)
    {
        cin >> weight[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> value[i];
    }
    int w;
    cin >> w;
    cout << knapsack(n, weight, value, w) << endl;
    return 0;
}
/*
Weight: 2 3 4 5
Value: 1 3 5 3
Limitation: 8Kg
*/