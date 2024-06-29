class Solution {
public:
    void DFS(int curr,vector<vector<int>> &adj,int ancestor,vector<vector<int>> &res)
    {
        for(auto nbrs:adj[curr])
        {
            if(res[nbrs].empty()||res[nbrs].back()!=ancestor)
            {
                res[nbrs].push_back(ancestor);
                DFS(nbrs,adj,ancestor,res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> adj(n);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++)
        {
            DFS(i,adj,i,res);
        }
        return res;
    }
};