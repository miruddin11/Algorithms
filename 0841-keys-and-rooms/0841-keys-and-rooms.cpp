class Solution {
public:
    void dfs(int src,vector<vector<int>> &rooms,vector<bool> &vis){
        vis[src]=true;
        for(int node:rooms[src]){
            if(!vis[node]){
                dfs(node,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);
        return (find(vis.begin(),vis.end(),false)!=vis.end())?false:true;
    }
};