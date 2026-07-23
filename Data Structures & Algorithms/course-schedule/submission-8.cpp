class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n = prereq.size();
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < n; i++) {
            adj[prereq[i][1]].push_back({prereq[i][0]});
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return !true;
            }
        }
        return !false;
    }
};
