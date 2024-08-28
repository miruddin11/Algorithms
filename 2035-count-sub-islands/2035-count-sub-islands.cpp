class Solution {
public:
    bool DFS(int i,int j,vector<vector<int>> &grid1,vector<vector<int>> &grid2)
    {
        if(i<0||i>=grid2.size()||j<0||j>=grid2[0].size()||grid2[i][j]!=1){
            return true;
        }
        grid2[i][j]=-1;
        bool ans=(grid1[i][j]==1);
        ans=ans & DFS(i-1,j,grid1,grid2);
        ans=ans & DFS(i,j+1,grid1,grid2);
        ans=ans & DFS(i+1,j,grid1,grid2);
        ans=ans & DFS(i,j-1,grid1,grid2);
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
                    if(DFS(i,j,grid1,grid2)){
                        cnt+=1;
                    }
                }
            }
        }
        return cnt;
    }
};