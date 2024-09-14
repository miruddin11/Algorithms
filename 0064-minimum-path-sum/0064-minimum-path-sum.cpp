class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n=grid.size(),m=grid[0].size();
        vector<int> prev(m);
        for(int i=0;i<n;i++)
        {
            vector<int> cur(m);
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0) cur[j]=grid[i][j];
                else if(i<0||j<0) cur[j]=INT_MAX;
                else{
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=min(up,left)+grid[i][j];
                }
            }
            prev=cur;
        }
        return prev[m-1];
    }
};