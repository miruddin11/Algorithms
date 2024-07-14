class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int zeroCount=0;
        int maxLen=0;
        while(j<n)
        {
            if(nums[j]==0) zeroCount+=1;
            while(zeroCount>k)
            {
                if(nums[i]==0) zeroCount--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};