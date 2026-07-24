class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        vector<int> temp1 = nums;
        vector<int> temp2 = nums;

        temp1.erase(temp1.begin());
        temp2.erase(temp2.end() - 1);

        int with_first_elem = f(n - 2, temp1, dp1);
        int with_last_elem = f(n - 2, temp2, dp2);

        return max(with_first_elem, with_last_elem);
    }

    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[i];

        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i - 2, nums, dp);
        int not_pick = 0 + f(i - 1, nums, dp);

        return dp[i] = max(pick, not_pick);
    }
};
