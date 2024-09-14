class Solution {
public:
    int dp[1001][1001];
    int n;
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
    int solve(vector<string> &words,int prev,int idx)
    {
        if(idx==n) return 0;
        if(prev!=-1&&dp[prev][idx]!=-1){
            return dp[prev][idx];
        }
        int take=0;
        if(prev==-1||isPredecessor(words[prev],words[idx])){
            take=1+solve(words,idx,idx+1);
        }
        int skip=solve(words,prev,idx+1);
        if(prev!=-1){
            return dp[prev][idx]=max(take,skip);
        }
        return max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        auto comp=[&](string &a,string &b){
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),comp);
        n=words.size();
        memset(dp,-1,sizeof(dp));
        return solve(words,-1,0);
    }
};