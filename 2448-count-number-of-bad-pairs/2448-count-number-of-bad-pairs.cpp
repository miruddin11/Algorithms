class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]-i;
        }
        unordered_map<int,int> mp;
        mp[nums[0]]=1;
        long long ans=0;
        for(int j=1;j<n;j++)
        {
            int cntofJ=mp[nums[j]];
            int totalnumbeforeJ=j;
            int badPairs=totalnumbeforeJ-cntofJ;
            ans+=badPairs;
            mp[nums[j]]+=1;
        }
        return ans;
    }
};