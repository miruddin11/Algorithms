class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x:nums){
            mp[x]++;
        }
        int maxf=0;
        for(auto i:mp){
            maxf=max(maxf,i.second);
        }
        int ans=0;
        for(auto i:mp)
        {
            if(i.second==maxf) ans+=i.second;
        }
        return ans;
    }
};