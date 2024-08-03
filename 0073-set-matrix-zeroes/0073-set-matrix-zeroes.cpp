static int speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	return 0;
}();
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0 && vis[i][j])
                {
                    int row=i;
                    while(row>=0){
                        if(matrix[row][j]!=0)
                        vis[row][j]=false;
                        matrix[row][j]=0;
                        row--;
                    }
                    row=i;
                    while(row<n)
                    {
                        if(matrix[row][j]!=0)
                        vis[row][j]=false;
                        matrix[row][j]=0;
                        row++;
                    }
                    int col=j;
                    while(col>=0)
                    {
                        if(matrix[i][col]!=0)
                        vis[i][col]=false;
                        matrix[i][col]=0;
                        col--;
                    }
                    col=j;
                    while(col<m)
                    {
                        if(matrix[i][col]!=0)
                        vis[i][col]=false;
                        matrix[i][col]=0;
                        col++;
                    }
                }
            }
        }
    }
};