class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        vector<vector<int>> g(n,vector<int>());
        for(const vector<int> & e:edges){
            int u=e[0];
            int v=e[1];
            g[u].push_back(v);
            indeg[v]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0){
                if(ans!=-1){
                    return -1;
                }
                ans=i;
            }
        }
        return ans;
    }
};