class Solution {
public:
    int dp[1001][1001];
    int solve(string &s,string &t,int i,int j)
    {
        if(i<=0||j<=0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i-1]==t[j-1]){
            return dp[i][j]=1+solve(s,t,i-1,j-1);
        }
        return dp[i][j]=max(solve(s,t,i-1,j),solve(s,t,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n=text1.size(),m=text2.size();
        return solve(text1,text2,n,m);
    }
};