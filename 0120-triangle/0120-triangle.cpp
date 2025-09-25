class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int row = 1; row < n; row++) {
            for(int col = 0; col<triangle[row].size(); col++) {
                int prev_up_val  = triangle[row-1][min(col, (int)triangle[row-1].size()-1)];
                int prev_up_left = triangle[row-1][max(col-1, 0)];
                
                triangle[row][col] += min(prev_up_val, prev_up_left);
            }
        }
        
        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};