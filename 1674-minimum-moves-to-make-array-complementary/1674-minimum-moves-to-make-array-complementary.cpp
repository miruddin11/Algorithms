class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; ++i) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);
            delta[2] += 2;            
            delta[a + 1] -= 1;         
            delta[a + b] -= 1;         
            delta[a + b + 1] += 1;     
            delta[b + limit + 1] += 1; 
        }
        int min_moves = n;
        int current_moves = 0;
        for (int target = 2; target <= 2 * limit; ++target) {
            current_moves += delta[target];
            min_moves = min(min_moves, current_moves);
        }
        return min_moves;
    }
};