class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int> &nums,int idx,bool flag)
    {
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        long long skip=solve(nums,idx+1,flag);
        long long val=nums[idx];
        if(flag==false){
            val=-val;
        }
        long long take=solve(nums,idx+1,!flag)+val;

        return dp[idx][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<long long>(2,-1));
        bool flag=true;
        return solve(nums,0,flag);
    }
};