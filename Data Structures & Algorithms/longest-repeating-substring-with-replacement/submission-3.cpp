class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;  // ans <= n

        int l = 0;
        int r = 0;

        vector<int> hash(26, 0);
        int maxFreq = 0;

        while (r < n) {
            int windowSize = r - l + 1;

            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            if (windowSize - maxFreq <= k) {
                ans = max(ans, windowSize);
            } else {
                hash[s[l] - 'A']--;
                l++;
            }
            r++;
        }

        return ans;
    }
};
