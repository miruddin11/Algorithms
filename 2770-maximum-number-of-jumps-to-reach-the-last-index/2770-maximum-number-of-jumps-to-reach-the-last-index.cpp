class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int> &nums, int target) {
        if(i == nums.size() - 1) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MIN;
        for(int j = i + 1; j < nums.size(); j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int val = 1 + solve(j, nums, target);
                ans = max(ans, val);
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        dp.resize(nums.size() + 1, -1);
        int ans = solve(0, nums, target);
        return ans < 0 ? -1 : ans;
    }
};