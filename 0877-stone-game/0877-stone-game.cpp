class Solution {
public:
    int dp[501][501][2];
    int solve(int left, int right, bool turn, vector<int> &piles) {
        if(left > right) {
            return 0;
        }
        if(dp[left][right][turn] != -1) {
            return dp[left][right][turn];
        }
        if(turn) {
            int fromLeft = piles[left] + solve(left + 1, right, false, piles);
            int fromRight = piles[right] + solve(left, right - 1, false, piles);
            return dp[left][right][turn] = max(fromLeft, fromRight);
        } else {
            int tookLeft = solve(left + 1, right, true, piles) - piles[left];
            int tookRight = solve(left, right - 1, true, piles) - piles[right];
            return dp[left][right][turn] = min(tookLeft, tookRight);
        }
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        return solve(0, n - 1, true, piles) > 0;
    }
};