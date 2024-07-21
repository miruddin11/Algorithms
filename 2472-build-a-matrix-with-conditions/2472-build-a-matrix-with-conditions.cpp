class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>> &edges,int n)
    {
        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(n+1,0);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            inDegree[v]+=1;
        }
        queue<int> q;
        int count=0;
        for(int i=1;i<=n;i++){
            if(inDegree[i]==0){
                q.push(i);
                count+=1;
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            result.push_back(u);
            for(auto &nbr:adj[u]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0){
                    q.push(nbr);
                    count++;
                }
            }
        }
        if(count!=n){
            return {};
        }

        return result;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow=topologicalSort(rowConditions,k);
        vector<int> topoCol=topologicalSort(colConditions,k);
        if(topoRow.empty()||topoCol.empty()){
            return {};
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[topoCol[i]]=i;
        }
        for(int i=0;i<k;i++)
        {
            int j=mp[topoRow[i]];
            ans[i][j]=topoRow[i];
        }
        return ans;
    }
};