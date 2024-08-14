class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totsum=0;
        for(auto &x:nums) totsum+=x;
        int leftsum=0;
        for(int i=0;i<nums.size();i++)
        {
            int rightsum=totsum-nums[i]-leftsum;
            if(leftsum==rightsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};