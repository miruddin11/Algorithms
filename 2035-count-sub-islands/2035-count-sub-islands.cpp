class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
    bool BFS(int i,int j,vector<vector<int>> &grid1,vector<vector<int>> &grid2)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid2[i][j]=-1;
        bool ans=true;
        while(!q.empty())
        {
            int currRow=q.front().first;
            int currCol=q.front().second;
            q.pop();
            if(grid1[currRow][currCol]!=1){
                ans=false;
            }
            for(auto &d:dir)
            {
                int row=currRow+d[0];
                int col=currCol+d[1];
                if(row<0||row>=grid2.size()||col<0||col>=grid2[0].size()||grid2[row][col]!=1){
                    continue;
                }
                grid2[row][col]=-1;
                q.push({row,col});
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0;
        for(int i=0;i<grid2.size();i++)
        {
            for(int j=0;j<grid2[0].size();j++)
            {
                if(grid2[i][j]==1)
                {
                    if(BFS(i,j,grid1,grid2)){
                        cnt+=1;
                    }
                }
            }
        }
        return cnt;
    }
};