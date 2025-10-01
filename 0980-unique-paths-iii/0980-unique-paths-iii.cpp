class Solution {
public:
    int m,n,uniquePath,obstacleCount;
    vector<vector<int>> direction={{-1,0},{1,0},{0,1},{0,-1}};
    void solve(vector<vector<int>> &grid,int cellCount,int i,int j)
    {
        if(i>=m||i<0||j>=n||j<0||grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(cellCount==obstacleCount){
                uniquePath++;
            }
            return;
        }
        //mark visited as cell
        grid[i][j]=-1;
        for(auto &dir:direction){
            int newI=i+dir[0],newJ=j+dir[1];
            solve(grid,cellCount+1,newI,newJ);
        }
        //back track
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        obstacleCount=1;//as start cell is also with no obstacle
        int startX=-1,startY=-1;
        m=grid.size(),n=grid[0].size(),uniquePath=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    obstacleCount+=1;
                }
                if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }
            }
        }
        solve(grid,0,startX,startY);
        return uniquePath;
    }
};