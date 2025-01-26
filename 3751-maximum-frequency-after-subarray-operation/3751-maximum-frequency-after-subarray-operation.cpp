class Solution {
public:
    int fun(vector<int> &nums,int targetValue,int k)
    {
        int cs=0;
        int ms=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==k) cs-=1;
            if(nums[i]==targetValue) cs+=1;
            if(cs<0) cs=0;
            ms=max(ms,cs);
        }
        return ms;
    }
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &x:nums) mp[x]+=1;
        int maxFreq=0;
        for(auto &[e,f]:mp)
        {
            maxFreq=max(maxFreq,fun(nums,e,k));
        }
        return mp[k]+maxFreq;
    }
};