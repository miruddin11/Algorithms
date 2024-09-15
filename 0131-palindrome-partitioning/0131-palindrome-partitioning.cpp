class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    void solve(int i,string s,vector<string> &temp)
    {
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(dp[i][j]==true){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.resize(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;
                if(i==j) dp[i][j]=true;
                else if(j==i+1) dp[i][j]= (s[i]==s[j]);
                else dp[i][j]= (s[i]==s[j] &&dp[i+1][j-1]);
            }
        }
        vector<string> temp;
        solve(0,s,temp);
        return ans;
    }
};