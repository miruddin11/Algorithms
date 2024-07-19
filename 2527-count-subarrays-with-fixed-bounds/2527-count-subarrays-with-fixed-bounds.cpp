class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minKposition=-1;
        int maxKposition=-1;
        int culpritIdx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxK || nums[i]<minK) culpritIdx=i;
            if(nums[i]==maxK) maxKposition=i;
            if(nums[i]==minK) minKposition=i;

            long long smaller=min(minKposition,maxKposition);
            long long temp=smaller-culpritIdx;
            ans+=(temp<=0)? 0LL: temp;
        }
        return ans;
    }
};