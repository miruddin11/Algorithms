class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string &s,string &t)
    {
        if(i==s.size()){
            return t.size()-j;
        }
        if(j==t.size()){
            return s.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(i+1,j+1,s,t);
        }
        int replace=1+solve(i+1,j+1,s,t);
        int del=1+solve(i+1,j,s,t);
        int insert=1+solve(i,j+1,s,t);
        return dp[i][j]=min(insert,min(replace,del));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};