class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> elem;
        int n = nums.size();
        multiset<int> ms;
        for (int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }

        int maxi = *ms.rbegin();
        elem.push_back(maxi);

        for (int i = k; i < n; i++) {
            auto it = ms.find(nums[i - k]);
            ms.erase(it);
            ms.insert(nums[i]);
            elem.push_back(*ms.rbegin());
        }

        return elem;
    }
};
