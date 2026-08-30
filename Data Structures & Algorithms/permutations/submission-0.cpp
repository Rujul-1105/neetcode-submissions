class Solution {
   public:
    void f(vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans, vector<int>& vis) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (!vis[i]) {
                curr.push_back(nums[i]);
                vis[i] = 1;
                f(curr, nums, ans, vis);
                curr.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int N = 1;
        for (int i = 0; i < n; i++) {
            N = nums[i] * N;
        }

        vector<int> vis(n, 0);
        vector<int> curr;
        vector<vector<int>> ans;

        f(curr, nums, ans, vis);

        return ans;
    }
};
