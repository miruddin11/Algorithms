class Solution {
public:
    bool isMagical(vector<vector<int>> &grid,int r,int c)
    {
        set<int> st;
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                if(st.find(grid[i][j])!=st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        int num=1;
        for(auto &x:st)
        {
            if(x!=num){
                return false;
            }
            num+=1;
        }
        int rowSum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=r;i<r+3;i++)
        {
            int sum=0;
            for(int j=c;j<c+3;j++)
            {
                sum+=grid[i][j];
            }
            if(sum!=rowSum){
                return false;
            }
        }
        for(int j=c;j<c+3;j++)
        {
            int sum=0;
            for(int i=r;i<r+3;i++)
            {
                sum+=grid[i][j];
            }
            if(sum!=rowSum){
                return false;
            }
        }
        int ldSum=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        if(ldSum!=rowSum){
            return false;
        }
        int rdSum=grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
        if(rdSum!=rowSum){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<=row-3;i++)
        {
            for(int j=0;j<=col-3;j++)
            {
                if(isMagical(grid,i,j)){
                    count+=1;
                }
            }
        }
        return count;
    }
};