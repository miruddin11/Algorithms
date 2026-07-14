class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[205][205][205];
    int solve(int idx, int g1, int g2, vector<int> &nums) {
        if(idx == nums.size()) {
            return (g1 > 0 && g1 == g2);
        }
        if(dp[idx][g1][g2] != -1) {
            return dp[idx][g1][g2];
        }
        int ans = 0;
        // Not take
        ans = solve(idx + 1, g1, g2, nums);

        // keeping in 1st seq
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, ng1, g2, nums)) % MOD;

        // keeping in 2nd seq
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, ng2, nums)) % MOD;

        return dp[idx][g1][g2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};