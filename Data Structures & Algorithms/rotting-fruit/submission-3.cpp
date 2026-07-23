class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        int cntfresh = 0;
        int time = -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1) cntfresh++;
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int lvl = q.front().second;
            q.pop();

            time = max(time, lvl);

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 &&
                    grid[nr][nc] == 1) {
                    q.push({{nr, nc}, lvl + 1});
                    cnt++;
                    vis[nr][nc] = 2;
                }
            }
        }

        if (cnt != cntfresh) {
            return -1;
        } else if (cnt == 0 && cntfresh == 0) {
            return 0;
        };

        return time;
    }
};
