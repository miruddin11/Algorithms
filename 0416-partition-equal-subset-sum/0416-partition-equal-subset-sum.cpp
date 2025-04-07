class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums) sum+=x;

        int reqsum=sum/2;
        int n=nums.size();
        int dp[n+1][reqsum+1];
        for(int i=0;i<n+1;i++)dp[i][0]=0;
        for(int j=0;j<reqsum+1;j++) dp[0][j]=0;

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<reqsum+1;j++)
            {
                if(nums[i-1]<=j)
                dp[i][j]=max(nums[i-1]+dp[i-1][j-nums[i-1]],dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        int sum2=sum-dp[n][reqsum];
        return dp[n][reqsum]==sum2;
    }
};