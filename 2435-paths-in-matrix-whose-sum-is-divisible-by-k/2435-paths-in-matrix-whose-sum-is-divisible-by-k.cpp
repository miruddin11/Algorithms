class Solution {
public:
    const int mod=1e9+7;
    int n,m,K;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int modVal,vector<vector<int>> &grid){
        if(i>=n||j>=m) return 0;
        if(i==n-1&&j==m-1){
            return ((grid[i][j]%K)==modVal);
        }
        if(dp[i][j][modVal]!=-1){
            return dp[i][j][modVal];
        }
        int remaining=(modVal-(grid[i][j]%K)+K)%K;
        return dp[i][j][modVal]=(solve(i+1,j,remaining,grid)+solve(i,j+1,remaining,grid))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        K=k;
        dp.resize(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return solve(0,0,0,grid)%mod;
    }
};