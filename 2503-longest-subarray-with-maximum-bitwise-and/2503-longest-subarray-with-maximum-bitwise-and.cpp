class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int len=0;
        int maxLen=0;
        for(auto &x:nums)
        {
            if(x==mx){
                len++;
            }
            else{
                len=0;
            }
            maxLen=max(len,maxLen);
        }
        return maxLen;
    }
};