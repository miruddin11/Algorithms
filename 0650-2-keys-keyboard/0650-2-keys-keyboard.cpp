class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[0]=0,dp[1]=0,dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int factor=i/2;
            while(factor>=1)
            {
                if(i%factor==0){
                    dp[i]=1+(i/factor -1 )+dp[factor];
                    break;
                }else{
                    factor--;
                }
            }
        }
        return dp[n];
    }
};