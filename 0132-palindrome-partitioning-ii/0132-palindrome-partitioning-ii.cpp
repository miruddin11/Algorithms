class Solution {
public:
    vector<vector<int>> dp;
    bool isPallindrome(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int j,string &s)
    {
        if(i>=j) return 0;
        if(isPallindrome(s,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mnCuts=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            if(isPallindrome(s,i,k)){
                int cuts=solve(k+1,j,s)+1;
                mnCuts=min(cuts,mnCuts);
            }
        }
        return dp[i][j]=mnCuts;
    }
    int minCut(string s) {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s);
    }
};