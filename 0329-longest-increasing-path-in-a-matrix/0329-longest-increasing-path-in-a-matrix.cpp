class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<pair<int,int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
        function<int(int,int)> dfs=[&](int i,int j){
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int ans=1;
            for(auto &d:dir)
            {
                int di=i+d.first;
                int dj=j+d.second;
                if(di>=0&&di<m&&dj>=0&&dj<n&&matrix[di][dj]>matrix[i][j]){
                    ans=max(ans,1+dfs(di,dj));
                }
            }
            return dp[i][j]=ans;
        };
        int LIP=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                LIP=max(LIP,dfs(i,j));
            }
        }
        return LIP;
    }
};