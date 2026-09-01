class Solution {
   public:
    int f(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind >= cost.size()) return 0;

        if (dp[ind] != -1) return dp[ind];

        dp[ind] = cost[ind] + min(f(ind + 1, cost, dp), f(ind + 2, cost, dp));
        return dp[ind];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};
