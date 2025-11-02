class Solution {
public:
    void markGuarded(int r,int c,vector<vector<char>> &grid)
    {
        for(int i=r-1;i>=0;i--){
            if(grid[i][c]=='G'||grid[i][c]=='W'){
                break;
            }
            grid[i][c]='S';
        }
        for(int i=r+1;i<grid.size();i++)
        {
            if(grid[i][c]=='G'||grid[i][c]=='W'){
                break;
            }
            grid[i][c]='S';
        }
        for(int j=c-1;j>=0;j--)
        {
            if(grid[r][j]=='G'||grid[r][j]=='W'){
                break;
            }
            grid[r][j]='S';
        }
        for(int j=c+1;j<grid[0].size();j++)
        {
            if(grid[r][j]=='G'||grid[r][j]=='W'){
                break;
            }
            grid[r][j]='S';
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m,vector<char>(n,'U'));
        for(auto &x:guards)
        {
            int i=x[0];
            int j=x[1];
            grid[i][j]='G';
        }
        for(auto &x:walls)
        {
            int i=x[0];
            int j=x[1];
            grid[i][j]='W';
        }
        for(auto &x:guards)
        {
            int i=x[0];
            int j=x[1];
            markGuarded(i,j,grid);
        }
        int cnt=0;
        for(auto &x:grid)
        {
            for(auto &y:x){
                if(y=='U') cnt+=1;
            }
        }
        return cnt;
    }
};