class Solution {
public:
    typedef long long ll;
    ll m = 1e9 + 7;
    ll exp(ll x, ll n) {
        x %= m;
        ll res = 1;
        while(n > 0) {
            if(n % 2 == 1) { 
                res = res * x % m; 
            }
            x = x * x % m;
            n /= 2;
        }
        return res;
    }
    int dfs(int u, vector<vector<int>> &adj, int par) {
        int depth = 0;
        for(auto &v : adj[u]) {
            if(v != par) {
                depth = max(depth, 1 + dfs(v, adj, u));
            }
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for(auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll maxDepth = dfs(1, adj, -1);
        return exp(2, maxDepth - 1);
    }
};