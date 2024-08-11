class Solution {
public:
    int count;
    int DFS(unordered_map<int,vector<int>> &adj,int curr,int parent)
    {
        int nodes=0,size=-1;
        int notGood=0;
        for(auto &nbrs:adj[curr])
        {
            if(nbrs==parent){
                continue;
            }
            // for the neighbor's the curr will be the parent
            int currsize=DFS(adj,nbrs,curr);
            if(size==-1){
                size=currsize;
            }
            else if(currsize!=size){
                notGood=1;
            }
            nodes+=currsize;
        }
        if(notGood==0){
            count++;
        }
        return nodes+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count=0;
        // 0's parent is -1
        DFS(adj,0,-1);
        return count;
    }
};