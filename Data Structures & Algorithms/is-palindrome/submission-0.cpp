class Solution {
   public:
    bool isPalindrome(string s) {
        string t;

        for (auto it : s) {
            if (isalnum(it)) {
                t += tolower(it);
            }
        }

        int i = 0;
        int j = t.size() - 1;

        while (i < j) {
            if (t[i] != t[j]) return false;

            i++;
            j--;
        }

        return 1;
    }
};
