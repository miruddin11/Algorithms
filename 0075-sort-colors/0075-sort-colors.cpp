class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0; //for 0
        int j = 0; //for 1
        int k = n - 1; //for 2
        while( j <= k ) {
            if(nums[j] == 1) {
                j++;
            } else if(nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};