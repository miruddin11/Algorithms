class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int resultIdx = 0;
        while(l <= r) {
            while(l < r && nums[l] == nums[l + 1])
                l++;
            while(l < r && nums[r] == nums[r - 1])
                r--;
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[resultIdx])
                resultIdx = mid;
            if(nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return nums[resultIdx];
    }
};