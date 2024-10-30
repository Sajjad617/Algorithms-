#include <bits/stdc++.h>
using namespace std;

int dp[10005];
int n;

int find_value(int op1) {
    if (op1 == n) {
        return 1;  // Reached the target value
    }
    else if (op1 > n) {
        return 0;  // Exceeded the target value
    }

    if (dp[op1] != -1) {
        return dp[op1];  // Return cached result
    }

    // Calculate possible outcomes
    return dp[op1] = find_value(op1 + 3) || find_value(op1 * 2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));  // Reset dp array
        cin >> n;  // Read the target value
        int op1 = 1;  // Starting point
        
        if (find_value(op1)) {
            cout << "YES" << endl;  // Found a way to reach n
        } else {
            cout << "NO" << endl;  // No valid path found
        }
    }
    return 0;
}