class Solution {
public:
    void numberOfIsland(int i,int j,vector<vector<int>> &matrix)
    {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size()||matrix[i][j]==1){
            return;
        }

        matrix[i][j]=1;
        numberOfIsland(i+1,j,matrix);
        numberOfIsland(i-1,j,matrix);
        numberOfIsland(i,j+1,matrix);
        numberOfIsland(i,j-1,matrix);
    }
    int regionsBySlashes(vector<string>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        int r=n*3,c=m*3;
        vector<vector<int>> matrix(r,vector<int>(c,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='\\'){
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
                else if(grid[i][j]=='/'){
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0){
                    numberOfIsland(i,j,matrix);
                    count++;
                }
            }
        }
        return count;
    }
};