class Solution {
   public:
    void f(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr); // because every combination is a valis subset

        for (int k = i; k < (int)nums.size(); k++) {
            if (k > i && nums[k] == nums[k - 1]) continue;

            curr.push_back(nums[k]);
            f(k + 1, nums, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if ((int)nums.size() == 0) return {{}};

        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());
        f(0, nums, curr, ans);
        return ans;
    }
};
