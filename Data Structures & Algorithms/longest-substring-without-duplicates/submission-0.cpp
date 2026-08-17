class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;

        map<char, int> seen;

        for (int j = 0; j < n; j++) {
            if (seen.find(s[j]) != seen.end()) {
                i = max(i, seen[s[j]] + 1);
            }
            seen[s[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
