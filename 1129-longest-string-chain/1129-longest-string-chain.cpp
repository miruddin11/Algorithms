class Solution {
public:
    bool isPredecessor(string &prev,string &curr)
    {
        int l=prev.size(),m=curr.size();
        if(m-l!=1){
            return false;
        }
        int i=0,j=0;
        while(i<l&&j<m){
            if(prev[i]==curr[j]){
                i++;
            }
            j++;
        }
        if(i==l) return true;

        return false;
    }
    int longestStrChain(vector<string>& words) {
        auto comp=[&](string &a,string &b){
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<int> dp(n,1);
        int maxLen=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isPredecessor(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
        return maxLen;
    }
};