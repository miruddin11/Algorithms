class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;
                if(i==j) dp[i][j]=0;
                else if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};