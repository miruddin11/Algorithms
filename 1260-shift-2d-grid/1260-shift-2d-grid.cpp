class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k % (n * m);
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int oldIndex = i * m + j;
                int newIndex = (oldIndex + k) % (n * m);
                int newRow = newIndex / m;
                int newCol = newIndex % m;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};