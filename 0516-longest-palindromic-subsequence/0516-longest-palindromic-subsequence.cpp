class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i<n-L+1;i++)
            {
                int j=i+L-1;
                if(i==j) dp[i][j]=1;
                else if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};