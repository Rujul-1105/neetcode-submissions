class Solution {
   public:
    void bfs(int n, vector<vector<int>>& adj, vector<int>& vis) {
        vis[n] = 1;

        queue<int> q;
        q.push(n);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        int cnt = 0;

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};
