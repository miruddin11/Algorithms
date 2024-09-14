class Solution {
public:
    int dp[1001][1001];
    int n;
    int solve(vector<vector<int>> &pairs,int idx,int prev)
    {
        if(idx==n){
            return 0;
        }
        if(prev!=-1&&dp[prev][idx]!=-1){
            return dp[prev][idx];
        }
        int take=0;
        if(prev==-1||pairs[idx][0]>pairs[prev][1]){
            take=1+solve(pairs,idx+1,idx);
        }
        int skip=solve(pairs,idx+1,prev);
        if(prev!=-1){
            return dp[prev][idx]=max(take,skip);
        }
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return solve(pairs,0,-1);
    }
};