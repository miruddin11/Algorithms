class Solution {
public:
    int dp[201][201];
    int solve(int m,int n,vector<vector<int>> &grid)
    {
        if(m==0&&n==0){
            return grid[m][n];
        }
        if(m<0||n<0){
            return 1e5;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up=1e5,left=1e5;
        if(m>0) up=solve(m-1,n,grid);
        if(n>0) left=solve(m,n-1,grid);
        return dp[m][n]=grid[m][n]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,grid);
    }
};