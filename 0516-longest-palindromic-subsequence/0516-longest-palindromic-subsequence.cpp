class Solution {
public:
    int dp[1001][1001];
    int LPS(int i,int j,string &s)
    {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]) return dp[i][j]=2+LPS(i+1,j-1,s);
        
        return dp[i][j]=max(LPS(i+1,j,s),LPS(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return LPS(0,n-1,s);
    }
};