class Solution {
public:
    int dp[55];
    int solve(int i,string &s,unordered_set<string> &st,int n)
    {
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1+solve(i+1,s,st,n);
        for(int j=i;j<n;j++){
            string curr=s.substr(i,j-i+1);
            if(st.find(curr)!=st.end()){
                ans=min(ans,solve(j+1,s,st,n));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        int n=s.size();
        return solve(0,s,st,n);
    }
};