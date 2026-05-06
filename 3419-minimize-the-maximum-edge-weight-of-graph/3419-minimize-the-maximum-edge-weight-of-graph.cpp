class Solution {
public:
    int N;
    void DFS(int node, vector<vector<pair<int, int>>> &adj, int mid, vector<bool> &visited) {
        visited[node] = true;
        for(auto &[nbr , wt] : adj[node]) {
            if(wt <= mid && visited[nbr] == false) {
                DFS(nbr, adj, mid, visited);
            }
        }
    }
    bool canReach(vector<vector<pair<int, int>>> &adj, int mid) {
        // We do reverse like from Zero can we reach each node
        vector<bool> visited(N, false);
        DFS(0, adj, mid, visited);
        for(int i = 0; i < N; i++) {
            if(visited[i] == false) {
                return false;
            }
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        int maxWeight = 0;
        N = n;
        for(auto &vec : edges) {
            int u = vec[0], v = vec[1], wt = vec[2];
            adj[v].push_back({u, wt}); // reverse edges => v --> u
            maxWeight = max(maxWeight, wt);
        }
        int l = 0, r = maxWeight;
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canReach(adj, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};