class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(f(cost, 0, dp), f(cost, 1, dp));
    }

    int f(vector<int> cost, int n, vector<int>& dp) {
        if (n >= cost.size()) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = cost[n] + min(f(cost, n + 1, dp), f(cost, n + 2, dp));

        return dp[n];
    }
};
