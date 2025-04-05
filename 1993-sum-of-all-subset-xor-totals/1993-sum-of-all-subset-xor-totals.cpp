class Solution {
public:
    int fun(vector<int> &nums,int idx,int xor_val)
    {
        if(idx==nums.size()) return xor_val;

        int include=fun(nums,idx+1,xor_val^nums[idx]);
        int exclude=fun(nums,idx+1,xor_val);
        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return fun(nums,0,0);
    }
};