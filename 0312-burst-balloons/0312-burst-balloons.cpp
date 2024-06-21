class Solution {
public:
    int dp[305][305];
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        for(int i=nums.size()-2;i>=1;i--)
        {
            for(int j=1;j<=nums.size()-2;j++)
            {
                if(i>j) dp[i][j]=0;
                else
                {
                    int ans=INT_MIN;
                    for(int k=i;k<=j;k++)
                    {
                        int coins=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                        ans=max(ans,coins);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[1][nums.size()-2];
    }
};