class Solution {
   public:
    void f(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == (int)nums.size()) {
            ans.push_back(curr);
            return;
        }

        f(i + 1, nums, curr, ans);  // notTake

        // take
        curr.push_back(nums[i]);
        f(i + 1, nums, curr, ans);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if ((int)nums.size() == 0) return {{}};

        vector<vector<int>> ans;
        vector<int> curr;

        f(0, nums, curr, ans);
        return ans;
    }
};
