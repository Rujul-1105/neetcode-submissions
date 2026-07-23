class Solution {
   public:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& area,
             int n, int m) {
        vis[row][col] = true;
        int cnt = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    cnt++;
                }
            }
        }
        // sum.push_back(cnt);
        //area = *max_element(sum.begin(), sum.end());
        area = max(area,cnt);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int area = 0;

        if (grid.empty()) return area;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    bfs(i, j, grid, vis, area, n, m);
                }
            }
        }

        return area;
    }
};
