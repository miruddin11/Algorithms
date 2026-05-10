class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        vector<int> degree(n, 0);
        for(auto &vec : roads) {
            int u = vec[0], v = vec[1];
            adj[u].insert(v);
            adj[v].insert(u);
            degree[u] += 1;
            degree[v] += 1;
        }
        int maxRank = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if(adj[i].count(j) > 0) {
                    rank -= 1;
                }
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};