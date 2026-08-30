class Solution {
public:
    void f(int open, int close, int n,
           string& curr, vector<string>& ans) {

        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can still place '('
        if (open < n) {
            curr.push_back('(');
            f(open + 1, close, n, curr, ans);
            curr.pop_back();
        }

        // ')' is allowed only when it won't make
        // the prefix invalid.
        if (close < open) {
            curr.push_back(')');
            f(open, close + 1, n, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        f(0, 0, n, curr, ans);

        return ans;
    }
};