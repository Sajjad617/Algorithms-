class Solution {
public:
    int dp[105];
    int fun(int n, vector<int> &nums)
    {
        if(n<0) return 0;

        if(dp[n] != -1) 
            return dp[n];

        int op1 = nums[n] + fun(n-2, nums);
        int op2 = fun(n-1, nums);

        return dp[n] = max(op1, op2);
    }
    int rob(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int total = fun(n-1, nums);
        return total;
    }
};