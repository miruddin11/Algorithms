class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for(int i = 0; i < n; i++) {
            int j = m - 1, prev = m - 1;
            while(j >= 0) {
                if(boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][prev]);
                    prev--;
                } else if(boxGrid[i][j] == '*') {
                    prev = j - 1;
                }
                j--;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[j][n - i - 1] = boxGrid[i][j];
            }
        }

        return ans;
    }
};