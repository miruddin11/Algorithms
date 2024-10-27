class Solution {
public:
    int m;
    int n;
    int dp[301][301];
    int solve(int i,int j,vector<vector<int>> &matrix)
    {
        if(i>=m||j>=n||matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left=solve(i,j+1,matrix);
        int down=solve(i+1,j,matrix);
        int diag=solve(i+1,j+1,matrix);

        return dp[i][j]=1+min({left,down,diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1){
                    ans+=solve(i,j,matrix);
                }
            }
        }
        return ans;
    }
};