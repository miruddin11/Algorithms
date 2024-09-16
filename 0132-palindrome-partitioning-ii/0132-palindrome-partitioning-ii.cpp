class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;
                if(i==j) t[i][j]=true;
                else if(j==i+1) t[i][j]= (s[i]==s[j]);
                else t[i][j]= (s[i]==s[j] &&t[i+1][j-1]);
            }
        }
        vector<int> dp(n);
        for(int k=0;k<n;k++)
        {
            if(t[0][k]==true){
                dp[k]=0;
            }
            else{
                dp[k]=INT_MAX;
                for(int i=0;i<k;i++)
                {
                    if(t[i+1][k]==true&&dp[i]+1<dp[k])
                    {
                        dp[k]=dp[i]+1;
                    }
                }
            }
        }
        return dp[n-1];
    }
};