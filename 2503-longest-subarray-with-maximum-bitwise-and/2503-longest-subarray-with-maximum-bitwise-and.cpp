class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int len=0,maxLen=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mx==nums[i]) len++;
            else len=0;
            maxLen=max(len,maxLen);
        }
        return maxLen;
    }
};