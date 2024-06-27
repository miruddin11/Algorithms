class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> inDegree(n+2,0);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            inDegree[u]++;
            inDegree[v]++;
        }
        for(int i=1;i<=n+1;i++){
            if(inDegree[i]==n) {
                return i;
            }
        }
        return 0;
    }
};