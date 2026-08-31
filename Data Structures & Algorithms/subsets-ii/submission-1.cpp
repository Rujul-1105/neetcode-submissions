class Solution {
   public:
    void f(vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans, vector<int>& vis) {
        if (curr.size() == nums.size()) {  // new permutation length same as the original
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = 1;
                curr.push_back(nums[i]);
                f(curr, nums, ans, vis);
                curr.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> curr;
        vector<vector<int>> ans;

        f(curr, nums, ans, vis);
        // n! number of permutation possible and the for loop runs n time
        // time complexity => O(n*n!)

        return ans;
    }
};
