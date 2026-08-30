class Solution {
   public:
    void create_map(map<int, vector<char>>& mpp) {
        char ch = 'a';
        for (int i = 2; i <= 9; i++) {
            if (i == 7 || i == 9) {
                for (int j = 0; j <= 3; j++) {
                    mpp[i].push_back(ch++);
                }
                continue;
            }
            for (int j = 0; j < 3; j++) {
                mpp[i].push_back(ch++);
            }
        }
    }

    void convert(string& digits, vector<int>& nums) {
        char ch = '0';
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            nums.push_back(digits[i] - ch);
        }
    }

    void f(int ind, vector<int>& nums, map<int, vector<char>>& mpp, vector<string>& ans,
           string& curr) {
        int n = nums.size();

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = nums[ind];

        for (char ch : mpp[digit]) {
            curr.push_back(ch);
            f(ind+1,nums,mpp,ans,curr);
            curr.pop_back();
        }
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == 7 || nums[i] == 9) {
        //         curr += mpp[nums[i]][i];
        //         f(ind + 1, nums, mpp, ans, curr);
        //         curr.pop_back();
        //     } else {
        //         for (int j = 0; j < 3; j++) {
        //             curr += mpp[nums[i]][j];
        //             f(ind + 1, nums, mpp, ans, curr);
        //             curr.pop_back();
        //         }
        //     }
        // }
    }

    vector<string> letterCombinations(string digits) {
        map<int, vector<char>> mpp;

        create_map(mpp);

        vector<int> nums;
        convert(digits, nums);

        int n = digits.size();
        if (n == 0) return {};

        vector<string> ans;
        string curr;
        f(0, nums, mpp, ans, curr);
        return ans;
    }
};
