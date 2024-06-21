class Solution {
public:
    int dfs(int curr,int parent,unordered_map<int,vector<int>> &adj,vector<bool> &hasApple)
    {
        int time=0;
        for(auto child:adj[curr])
        {
            if(child==parent) continue;
            int time_from_my_child=dfs(child,curr,adj,hasApple);
            if(time_from_my_child>0||hasApple[child]){
                time+= time_from_my_child+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,-1,adj,hasApple);
    }
};