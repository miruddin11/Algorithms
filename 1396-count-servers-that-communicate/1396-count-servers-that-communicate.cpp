class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> colServerCount(n, 0);
        vector<int> RowAkelaServerCol(m, -1);
        int resultServers = 0;
        for(int row = 0; row < m; row++) {
            int countServersRow = 0;
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    countServersRow += 1;
                    colServerCount[col]++;
                    RowAkelaServerCol[row] = col;
                }
            }
            if(countServersRow > 1) {
                resultServers += countServersRow;
                RowAkelaServerCol[row] = -1;
            }
        }
        for(int row = 0; row < m; row++) {
            if(RowAkelaServerCol[row] != -1) {
                int col = RowAkelaServerCol[row];
                if(colServerCount[col] > 1) {
                    resultServers += 1;
                }
            }
        }
        return resultServers;
    }
};