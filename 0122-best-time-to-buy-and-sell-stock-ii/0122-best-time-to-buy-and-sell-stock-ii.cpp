class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int holdingStock, vector<int> &prices) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][holdingStock] != -1) {
            return dp[i][holdingStock];
        }
        int currPrice = prices[i];
        int profit = solve(i + 1, holdingStock, prices);
        if(holdingStock == 0) {
            profit = max(profit, -currPrice + solve(i + 1, 1, prices));
        } else {
            profit = max(profit, currPrice + solve(i + 1, 0, prices));
        }
        
        return dp[i][holdingStock] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(0, 0, prices);
    }
};