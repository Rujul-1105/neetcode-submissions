class Solution {
   public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void f(int ind, string& s, vector<vector<string>>& ans, vector<string>& curr) {
        if (ind == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                curr.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, s, ans, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        f(0, s, ans, curr);
        return ans;
    }
};
