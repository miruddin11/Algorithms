class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size=nums.size()-1;
        while(size>0){
            for(int i=0;i<size;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            size--;
        }
        return nums[0];
    }
};