class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(begin(nums), end(nums));
        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i - 1];
            while(nums[i] - x > 1) {
                x++;
                ans.push_back(x);
            }
        }
        return ans;
    }
};