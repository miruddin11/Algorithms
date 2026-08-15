class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool z = true;
        for(int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
            if(nums[i] != 0) z = false;
        }
        if(z) return 0;
        if(x != 0) return nums.size();
        return nums.size() - 1;
    }
};