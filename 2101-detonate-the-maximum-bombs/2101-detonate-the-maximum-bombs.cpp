class Solution {
public:
    typedef long long ll;
    void dfs(int u,unordered_map<int,vector<int>> &adj,unordered_set<int> &vis){
        vis.insert(u);
        for(int v:adj[u]){
            if(vis.count(v)==0){
                dfs(v,adj,vis);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            ll x1=bombs[i][0],y1=bombs[i][1],r1=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                ll x2=bombs[j][0],y2=bombs[j][1];
                ll dx=abs(x2-x1),dy=abs(y2-y1);
                ll d=dx*dx+dy*dy;
                if((r1*r1)>=d){
                    adj[i].push_back(j);
                }
            }
        }
        int maxCount=0;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            vis.clear();
            dfs(i,adj,vis);
            int count=vis.size();
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};