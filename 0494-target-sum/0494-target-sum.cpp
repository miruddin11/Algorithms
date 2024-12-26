class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0;
        int d=target;
        for(auto &x:nums) sum+=x;
        if(sum<d||d<-sum||(d+sum)%2!=0) return 0;
        int targetSum=(d+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(targetSum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=targetSum;j++)
            {
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][targetSum];
    }
};