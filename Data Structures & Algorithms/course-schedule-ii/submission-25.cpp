class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis,
             vector<int>& ans) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, ans)) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        ans.push_back(node);
        pathVis[node] = 0;

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int n = prereq.size();
        vector<vector<int>> adj(numCourses);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, ans)) {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
