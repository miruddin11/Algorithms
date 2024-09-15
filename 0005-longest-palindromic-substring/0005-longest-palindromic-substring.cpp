class Solution {
public:
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n=s.size();
        int maxLen=0;
        int start_idx=-1;
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;
                if(i==j) t[i][j]=true;
                else if(j==i+1) t[i][j]=(s[i]==s[j]);
                else{
                    t[i][j]=( s[i]==s[j] && t[i+1][j-1] );
                }
                if(t[i][j]==true){
                    if(maxLen<j-i+1){
                        maxLen=j-i+1;
                        start_idx=i;
                    }
                }
            }
        }
        return s.substr(start_idx,maxLen);
    }
};