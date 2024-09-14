class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>> &grid)
    {
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size()||j>=grid[0].size()){
            return 1e5;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=solve(i+1,j,grid);
        int right=solve(i,j+1,grid);
        return dp[i][j]=grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};