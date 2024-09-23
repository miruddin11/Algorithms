class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=1+dp[i+1];
            for(int j=i;j<n;j++){
                string curr=s.substr(i,j-i+1);
                if(st.find(curr)!=st.end()){
                    dp[i]=min(dp[i],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};