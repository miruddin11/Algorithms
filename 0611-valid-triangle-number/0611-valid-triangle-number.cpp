class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(begin(nums), end(nums));
        int count = 0;
        for(int k = n-1; k > 1; k--) {
            int i = 0, j = k-1;           
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } 
                else {
                    i++;
                }
            }
        }
        return count;
    }
};