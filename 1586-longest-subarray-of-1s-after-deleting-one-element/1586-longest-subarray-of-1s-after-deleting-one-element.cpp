class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int countZero=0;
        int i=0,j=0;
        int maxLen=0;
        while(j<n)
        {
            if(nums[j]==0) countZero++;
            
            while(countZero>1){
                if(nums[i]==0) countZero--;
                i++;
            }
            maxLen=max(maxLen,j-i);
            j++;
        }
        return maxLen;
    }
};