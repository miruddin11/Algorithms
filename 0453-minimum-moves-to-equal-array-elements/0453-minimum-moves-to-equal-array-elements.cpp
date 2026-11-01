class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        long long ans = 0;
        for(auto &num : nums) {
            ans += num - minimum;
        }
        return ans;
    }
};