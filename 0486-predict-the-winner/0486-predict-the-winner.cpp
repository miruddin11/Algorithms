class Solution {
public:
    vector<vector<int>> dp;
    int score(const vector<int>& nums, int l, int r) {
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        if(l == r) {
            return nums[l];
        }
        int left = nums[l] - score(nums, l + 1, r);
        int right = nums[r] - score(nums, l, r - 1);
        dp[l][r] = max(left, right);
        return dp[l][r];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return score(nums, 0, n - 1) >= 0;
    }
};