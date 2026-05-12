class Solution {
public:
    unordered_map<int, int> mp;
    int n;
    vector<vector<int>> dp;
    bool solve(int currStoneIdx, int prevJump, vector<int> &stones) {
        if(currStoneIdx == n - 1) {
            return true;
        }
        if(dp[currStoneIdx][prevJump] != -1) {
            return dp[currStoneIdx][prevJump];
        }
        bool ans = false;
        for(int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if(nextJump > 0) {
                int nextStone = stones[currStoneIdx] + nextJump;
                if(mp.find(nextStone) != mp.end()) {
                    ans = ans || solve(mp[nextStone], nextJump, stones);
                }
            }
        }
        return dp[currStoneIdx][prevJump] = ans;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1) {
            return false;
        }
        dp.resize(n + 1, vector<int>(n + 1, -1));
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        return solve(mp[0], 0, stones);
    }
};