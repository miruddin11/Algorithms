class Solution {
public:
    int width;
    vector<vector<int>> dp;
    int solve(int i,vector<vector<int>> &books,int remWidth,int maxHeight)
    {
        if(i>=books.size()) return maxHeight;
        if(dp[i][remWidth]!=-1){
            return dp[i][remWidth];
        }
        int take=INT_MAX,notTake=INT_MAX;
        int w=books[i][0],h=books[i][1];
        if(w<=remWidth){
            take=solve(i+1,books,remWidth-w,max(maxHeight,h));
        }
        notTake=maxHeight+solve(i+1,books,width-w,h);

        return dp[i][remWidth]=min(take,notTake);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp.resize(1001,vector<int>(1001,-1));
        width=shelfWidth;
        return solve(0,books,shelfWidth,0);
    }
};