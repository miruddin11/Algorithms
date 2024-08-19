class Solution {
public:
    int dp[1001][1001];
    int solve(int s,int c,int n)
    {
        if(s>n){
            return 1e5;
        }
        if(s==n){
            return 0;
        }
        if(dp[s][c]!=-1){
            return dp[s][c];
        }
        int copy=1e5;
        int paste=1e5;
        if(s==c){
            paste=solve(s+c,c,n);
        }
        else{
            paste=solve(s+c,c,n);
            copy=solve(s,s,n);
        }
        return dp[s][c]=1+min(copy,paste);
    }
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        if(n==1){
            return 0;
        }
        return 1+solve(1,1,n);
    }
};