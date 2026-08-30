class Solution {
   public:
    bool isSafe(int r, int c, vector<string>& board) {
        // col
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        // Diagonal 1
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // Diagonal 2
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void f(int index, vector<string>& row, vector<vector<string>>& ans) {
        if (index == row.size()) {
            ans.push_back(row);
            return;
        }
        for (int c = 0; c < row.size(); c++) {
            if (isSafe(index, c, row)) {
                row[index][c] = 'Q';
                f(index + 1, row, ans);
                row[index][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> row(n, string(n, '.'));
        f(0, row, ans);
        return ans;
    }
};
