class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int k, vector<vector<int>> &grid, int cost) {
        if(i >= n || j >= m) {
            return INT_MIN;
        }
        int newCost = cost + (grid[i][j] > 0 );
        if(newCost > k) {
            return INT_MIN;
        }
        if(i == n - 1 && j == m - 1) {
            return grid[i][j];
        }
        if(dp[i][j][cost] != -1) {
            return dp[i][j][cost];
        } 
        int right = solve(i, j + 1, k, grid, newCost);
        int down = solve(i + 1, j, k, grid, newCost);
        if(right == INT_MIN && down == INT_MIN) {
            return dp[i][j][cost] = INT_MIN;
        }

        return dp[i][j][cost] = grid[i][j] + max(right, down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        int ans = solve(0, 0, k, grid, 0);
        return ans == INT_MIN ? -1 : ans;
    }
};