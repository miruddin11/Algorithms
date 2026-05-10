class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[i] - nums[j]) <= target && dp[j] != INT_MIN) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }   
            }
        }
        return dp[0] < 0 ? -1 : dp[0];
    }
};