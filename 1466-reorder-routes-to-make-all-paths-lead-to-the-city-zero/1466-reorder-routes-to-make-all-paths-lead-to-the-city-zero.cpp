class Solution {
public:
    int flips;
    void solve(int u, int parent, vector<bool>& vis,
               unordered_map<int, vector<pair<int, int>>>& adj) {
        vis[u] = true;
        for (auto& [v, f] : adj[u]) {
            if (!vis[v] && v != parent) {
                if (f == 1) {
                    // getting away from the zero with an existed edge so needs
                    // to flip
                    flips += 1;
                }
                solve(v, u, vis, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& c : connections) {
            int u = c[0], v = c[1];
            // 1=> for already existed edge = u--->v
            adj[u].push_back({v, 1});
            // 0=> for create edges by me = v--->u
            adj[v].push_back({u, 0});
        }
        flips = 0;
        vector<bool> vis(n, false);
        solve(0, -1, vis, adj);
        return flips;
    }
};