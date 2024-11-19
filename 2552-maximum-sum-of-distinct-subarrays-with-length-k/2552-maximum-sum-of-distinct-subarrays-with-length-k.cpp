class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum=0,ans=0;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
            sum+=nums[i];
        }
        if(mp.size()==k) ans=max(ans,sum);
        for(int i=k;i<nums.size();i++)
        {
            int val=nums[i-k];
            sum-=val;
            mp[val]--;
            if(mp[val]==0){
                mp.erase(val);
            }
            mp[nums[i]]++;
            sum+=nums[i];
            if(mp.size()==k) ans=max(ans,sum);
        }
        return ans;
    }
};