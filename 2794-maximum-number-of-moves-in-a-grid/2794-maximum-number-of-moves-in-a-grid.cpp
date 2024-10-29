class Solution {
public:
    int m,n;
    vector<int> dir={-1,0,1};
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>> &grid)
    {
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(auto &d:dir)
        {
            int r=i+d;
            int c=j+1;

            if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]>grid[i][j]){
                ans=max(ans,1+solve(r,c,grid));
            }
        }
        return dp[i][j]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        int mxMoves=0;
        for(int i=0;i<m;i++){
            mxMoves=max(mxMoves,solve(i,0,grid));
        }
        return mxMoves;
    }
};