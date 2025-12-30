class Solution {
public:
    bool isMagical(int row,int col,vector<vector<int>> &grid){
        set<int> st;
        //duplicate check
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(st.find(grid[i][j])!=st.end()){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        // checking grid contains 1 to 9 in it
        int num=1;
        for(auto &x:st){
            if(x!=num){
                return false;
            }
            num+=1;
        }
        // checking for each row 
        int rowSum=grid[row][col]+grid[row][col+1]+grid[row][col+2];
        for(int i=row+1;i<row+3;i++){
            int sum=0;
            for(int j=col;j<col+3;j++){
                sum+=grid[i][j];
            }
            if(sum!=rowSum){
                return false;
            }
        }
        //checking for each column
        for(int j=col;j<col+3;j++){
            int sum=0;
            for(int i=row;i<row+3;i++){
                sum+=grid[i][j];
            }
            if(rowSum!=sum){
                return false;
            }
        }
        // left diagonal sum
        int leftDiaSum=grid[row][col]+grid[row+1][col+1]+
            grid[row+2][col+2];
        if(leftDiaSum!=rowSum){
            return false;
        }
        // right diagonal sum
        int rightDiaSum=grid[row][col+2]+grid[row+1][col+1]+
        grid[row+2][col];
        if(rightDiaSum!=rowSum){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i+3<=n;i++){
            for(int j=0;j+3<=m;j++){
                if(isMagical(i,j,grid)){
                    count+=1;
                }
            }
        }
        return count;
    }
};