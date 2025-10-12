class Solution {
public:
    vector<int> ans;
    vector<int> dfs(int u,int parent,unordered_map<int,vector<int>> &adj,string &labels){
        vector<int> myCount(26,0);
        char myLabel=labels[u];
        myCount[myLabel-'a']=1;
        for(auto &v:adj[u]){
            if(v!=parent){
                vector<int> childCount=dfs(v,u,adj,labels);
                for(int i=0;i<26;i++){
                    myCount[i]+=childCount[i];
                }
            }
        }
        ans[u]=myCount[myLabel-'a'];
        return myCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) { 
        ans.resize(n,0);
        unordered_map<int,vector<int>> adj;
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj,labels);
        return ans;
    }
};