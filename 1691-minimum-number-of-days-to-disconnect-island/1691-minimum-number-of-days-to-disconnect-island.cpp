class Solution {
public:
    int n,m;
    void DFS(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &vis)
    {
        if(i>=n||i<0||j>=m||j<0||vis[i][j]==1||grid[i][j]==0){
            return;
        }
        vis[i][j]=1;
        DFS(grid,i-1,j,vis);
        DFS(grid,i+1,j,vis);
        DFS(grid,i,j-1,vis);
        DFS(grid,i,j+1,vis);
    }
    int countIsland(vector<vector<int>> &grid)
    {
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                    DFS(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int island=countIsland(grid);
        if(island==0||island>1){
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    island=countIsland(grid);
                    if(island>1||island==0){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};