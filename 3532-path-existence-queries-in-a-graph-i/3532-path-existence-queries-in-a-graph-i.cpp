class Solution {
public:
    void dfs(int cur, int compId, unordered_map<int, vector<int>>& adj, vector<int>& component) {
        component[cur] = compId;
        for (int& ngbr : adj[cur]) {
            if (component[ngbr] == -1) {
                dfs(ngbr, compId, adj, component);
            }
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
        }

        vector<int> component(n, -1);
        int compId = 0;
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                dfs(i, compId, adj, component);
                compId++;
            }
        }
        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }
        return result;
    }
};