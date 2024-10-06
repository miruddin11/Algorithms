class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(vector<vector<char>> &grid,int i,int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        for(auto &v:dir)
        {
            int di=i+v[0];
            int dj=j+v[1];
            dfs(grid,di,dj);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'){
                    cnt+=1;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};