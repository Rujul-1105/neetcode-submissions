class Solution {
   public:
    void f(int i, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == (int)nums.size()) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        if (nums[i] <= target) {
            curr.push_back(nums[i]);
            f(i, target - nums[i], nums, curr, ans);
            curr.pop_back();
        }

        f(i + 1, target, nums, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        f(0, target, nums, curr, ans);
        return ans;
    }
};
