class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<int> dp(target + 1 , 0);
        dp[0] = 1;
        int Mod = 1e9 + 7;
        for(auto &t : types) {
            int count = t[0] , marks = t[1];
            for(int j = target; j >= marks; j--) {
                for(int k = 1; k <= count && k * marks <= j ; k++) {
                    dp[j] = (dp[j] + dp[j - k * marks]) % Mod;
                }
            }
        }
        return dp[target] % Mod;
    }
};