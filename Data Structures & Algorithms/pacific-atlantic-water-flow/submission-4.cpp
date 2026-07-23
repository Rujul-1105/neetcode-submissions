class Solution {
   public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !vis[nr][nc] &&
                (grid[row][col] <= grid[nr][nc])) {
                dfs(nr, nc, grid, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //  {n-1,0} and {0,m-1}

        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pac);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pac);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atl);
        }
        for (int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atl);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
