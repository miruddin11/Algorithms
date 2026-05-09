class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int topRow = 0, bottomRow = n - 1;
        int leftCol = 0, rightCol = m - 1;
        while(topRow < bottomRow && leftCol < rightCol) {
            int len = bottomRow - topRow, width = rightCol - leftCol;
            int perimeter = 2 * (len + width);
            int r = k % perimeter;
            while(r > 0) {
                int temp = grid[topRow][leftCol];
                // Shift top row elements to the left by 1 position
                for(int j = leftCol; j < rightCol; j++) {
                    grid[topRow][j] = grid[topRow][j + 1];
                }
                // Shift right column elements up by 1 position
                for(int i = topRow; i < bottomRow; i++) {
                    grid[i][rightCol] = grid[i + 1][rightCol];
                }
                // Shift bottom row elements to the right by 1 position
                for(int j = rightCol; j > leftCol; j--) {
                    grid[bottomRow][j] = grid[bottomRow][j - 1];
                }
                // Shift left column elements down by 1 position
                for(int i = bottomRow; i > topRow; i--) {
                    grid[i][leftCol] = grid[i - 1][leftCol];
                }
                grid[topRow + 1][leftCol] = temp;
                r--;
            }
            topRow++; leftCol++;
            bottomRow--; rightCol--;
        }
        return grid;
    }
};