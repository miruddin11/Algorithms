class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long ans=INT_MIN;
        int n=nums.size();
        map<int,long long> mp;
        mp[INT_MIN]=0;
        for(int i=0;i<n;i++)
        {
            auto it=mp.upper_bound(nums[i]-i);
            long long sum=nums[i];
            if(it!=mp.begin())
            {
                it--;
                sum+=it->second;
            }
            mp[nums[i]-i]=max(mp[nums[i]-i],sum);
            it=mp.upper_bound(nums[i]-i);
            while(it!=mp.end()&&it->second<=sum){
                mp.erase(it++);
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};