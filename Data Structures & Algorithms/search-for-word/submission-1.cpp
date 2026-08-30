class Solution {
   public:
    bool dfs(vector<vector<char>>& grid, string word, int row, int col, int ind) {
        int n = grid.size();
        int m = grid[0].size();

        if (ind == (int)word.size()) return true;

        // out of bounds
        if (row < 0 || row >= n || col < 0 || col >= m) return false;
        // next char not matching
        if (grid[row][col] != word[ind]) return false;

        // a cell can be used at most once in a single path.
        // word = ABCB, grid = ["ABCE", "QWER", "ASAF"]; 
        char temp = grid[row][col];
        grid[row][col] = '#';

        bool found =
            dfs(grid, word, row + 1, col, ind + 1) || dfs(grid, word, row - 1, col, ind + 1) ||
            dfs(grid, word, row, col + 1, ind + 1) || dfs(grid, word, row, col - 1, ind + 1);

        grid[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
