class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                for(int cost = k; cost >= 0; cost --) {
                    int newCost = cost + (grid[i][j] > 0);
                    if(newCost > k) {
                        continue;
                    } 
                    if(i == n - 1 && j == m - 1) {
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }
                    int right = dp[i][j + 1][newCost];
                    int down = dp[i + 1][j][newCost];
                    int bestNext = max(right, down);
                    if(bestNext != -1) {
                        dp[i][j][cost] = bestNext + grid[i][j];
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};