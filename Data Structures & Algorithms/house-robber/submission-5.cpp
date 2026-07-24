class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return f(n - 1, nums, dp);
    }

    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[i];

        // dp[0] = nums[0];

        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i - 2, nums, dp);
        int not_pick = 0 + f(i - 1, nums, dp);

        return dp[i] = max(pick, not_pick);
    }
};
