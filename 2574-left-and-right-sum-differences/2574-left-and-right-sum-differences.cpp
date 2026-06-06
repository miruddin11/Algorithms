class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0, n = nums.size();
        for(auto &num : nums) {
            totalSum += num;
        }
        int leftSum = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int rightSum = totalSum - nums[i] - leftSum;
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};