class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto &i : adj[node]) {
            if (!vis[i]) {
                dfs(i, adj, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        for (auto &vec : invocations) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n, false);
        dfs(k, adj, vis);
        vector<int> ans;
        for (auto &vec : invocations) {
            int u = vec[0];
            int v = vec[1];
            if (!vis[u] && vis[v]) {
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};