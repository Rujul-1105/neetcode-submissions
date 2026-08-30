class Solution {
   public:
    int bs(int left, int right, vector<int>& nums, int target) {
        // Base case
        if (left > right) return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target) {
            left = mid + 1;
            return bs(left, right, nums, target);
        } else {
            right = mid - 1;
            return bs(left, right, nums, target);
        }

        return INT_MIN;
    }
    int search(vector<int>& nums, int target) { return bs(0, (int)nums.size() - 1, nums, target); }
};
