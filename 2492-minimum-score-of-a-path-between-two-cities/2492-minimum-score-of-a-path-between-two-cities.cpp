class Solution {
public:
    int ans;
    void DFS(int u, unordered_map<int, vector<pair<int,int>>> &adj, vector<int> &vis) {
        vis[u] = 1;
        for(auto &[v, d] : adj[u]) {
            ans = min(ans, d);
            if(vis[v] == 0) {
                DFS(v, adj, vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        ans = INT_MAX;
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &r : roads) {
            int u = r[0], v = r[1], d = r[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<int> vis(n + 1, 0);
        DFS(1, adj, vis);
        return ans;
    }
};