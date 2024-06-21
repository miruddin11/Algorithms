class Solution {
public:
    //int dp[305][305];
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int> &nums)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int coins=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums);
            ans=max(ans,coins);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        //memset(dp,-1,sizeof(dp));
        dp.resize(nums.size()+3,vector<int>(nums.size()+3,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(1,nums.size()-2,nums);
    }
};