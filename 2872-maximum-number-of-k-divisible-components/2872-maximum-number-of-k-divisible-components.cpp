class Solution {
public:
    int count;
    int dfs(int node,unordered_map<int,vector<int>> &adj,vector<int> &values,int k,int parent)
    {
        long long sum=values[node];
        for(auto &nbr:adj[node])
        {
            if(nbr!=parent)
            {
                sum+=dfs(nbr,adj,values,k,node);
            }
        }
        sum%=k;
        if(sum==0){
            count+=1;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>> adj;
        count=0;
        for(auto &vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,adj,values,k,-1);
        return count;
    }
};