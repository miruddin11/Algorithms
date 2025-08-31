class Solution {
public:
    bool valid(int i,int j,vector<vector<char>>& board,char c)
    {
        // row and col
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==c||board[k][j]==c)
            return false;
        }
        // grid
        int row=(i/3) *3 ;
        int col=(j/3) *3;
        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(board[i][j]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<char>>& board)
    {
        if(i==9)
        {
           return true; 
        }
        if(j==9)
        {
            return solve(i+1,0,board);
        }
        if(board[i][j]!='.'){
            return solve(i,j+1,board);
        }
        for(char ch='1';ch<='9';ch++)
        {
            //valid condition should be here
            if(!valid(i,j,board,ch)){
                continue;
            }
            board[i][j]=ch;
            if(solve(i,j+1,board)) return true;
            board[i][j]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};