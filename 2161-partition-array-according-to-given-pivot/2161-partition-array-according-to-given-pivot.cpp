class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int sameCount = count(begin(nums), end(nums), pivot);
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                ans[j] = nums[i];
                j += 1;
            }
        }
        for(int i = 0; i < sameCount; i++) {
            ans[j] = pivot;
            j++;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > pivot) {
                ans[j] = nums[i];
                j += 1;
            }
        }
        return ans;
    }
};