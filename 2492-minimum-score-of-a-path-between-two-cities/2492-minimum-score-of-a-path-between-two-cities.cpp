class Solution {
public:
    int mnScore;
    void dfs(int u,unordered_map<int,vector<pair<int,int>>> &adj,vector<bool> &vis){
        vis[u]=true;
        for(auto &[v,d]:adj[u]){
            mnScore=min(mnScore,d);
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        mnScore=INT_MAX;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &r:roads){
            int u=r[0],v=r[1],d=r[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool> vis(n,false);
        dfs(1,adj,vis);
        return mnScore;
    }
};