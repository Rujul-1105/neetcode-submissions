class Solution {
   public:
    void f(int i, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        // base case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // take
        for (int k = i; k < (int)nums.size(); k++) {
            if (k > i && nums[k] == nums[k - 1]) continue;

            if (nums[k] > target) break;

            curr.push_back(nums[k]);
            f(k + 1, target - nums[k], nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        f(0, target, nums, curr, ans);
        
        return ans;
    }
};
