class Solution {
public:
    int dp[302];
    bool solve(int i,string &s,unordered_set<string> &st,int n)
    {
        if(i>=n){
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        if(st.find(s)!=st.end()){
            return true;
        }
        for(int l=1;l<=n;l++)
        {
            string curr=s.substr(i,l);
            if(st.find(curr)!=st.end()&&solve(i+l,s,st,n)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        return solve(0,s,st,n);
    }
};