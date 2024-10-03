class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0;
        for(auto &x:nums){
            sum=(sum+x)%p;
        }
        int target=sum%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int> mp;
        int n=nums.size();
        int curr=0;
        int ans=n;
        mp[0]=-1;
        for(int j=0;j<n;j++)
        {
            curr=(curr+nums[j])%p;
            int prev=(curr-target+p)%p;
            if(mp.find(prev)!=mp.end()){
                int i=mp[prev];
                int len=j-i;
                ans=min(ans,len);
            }
            mp[curr]=j;
        }
        return ans==n?-1:ans;
    }
};