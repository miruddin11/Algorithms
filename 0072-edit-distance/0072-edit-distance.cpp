class Solution {
public:
    int dp[501][501];
    int solve(int m,int n,string &s,string &t)
    {
        if(m==0){
            return n;
        }
        if(n==0){
            return m;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m-1]==t[n-1]){
            return dp[m][n]=solve(m-1,n-1,s,t);
        }
        int replace=1+solve(m-1,n-1,s,t);
        int del=1+solve(m-1,n,s,t);
        int insert=1+solve(m,n-1,s,t);
        return dp[m][n]=min(insert,min(replace,del));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(m,n,word1,word2);
    }
};