class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx,int d,int n,vector<int> &jD)
    {
        if(d==1){
            return *max_element(jD.begin()+idx,jD.end());
        }
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        int finalResult=INT_MAX;
        int maxD=jD[idx];
        for(int i=idx;i<=n-d;i++)
        {
            maxD=max(maxD,jD[i]);
            int result=maxD+solve(i+1,d-1,n,jD);
            finalResult=min(finalResult,result);
        }
        return dp[idx][d]=finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        dp.resize(n+1,vector<int>(d+1,-1));
        if(n<d) return -1;
        return solve(0,d,n,jobDifficulty);
    }
};