class Solution {
public:
    int dp[2][101][101];
    int n;
    int solve(vector<int> &piles,int person,int i,int M)
    {
        if(i>=n){
            return 0;
        }
        if(dp[person][i][M]!=-1){
            return dp[person][i][M];
        }
        int ans=(person==1)?-1:INT_MAX;
        int stones=0;
        for(int x=1;x<=min(2*M,n-i);x++)
        {
            stones+=piles[i+x-1];
            if(person==1){
                ans=max(ans,stones+solve(piles,0,i+x,max(M,x)) );
            }
            else{
                ans=min(ans,solve(piles,1,i+x,max(M,x)));
            }
        }
        return dp[person][i][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        n=piles.size();
        return solve(piles,1,0,1);
    }
};