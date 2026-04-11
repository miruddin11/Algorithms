class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans=1e9;
        for(auto it:mp)
        {
            vector<int> v = it.second;
            if(v.size()>=3)
            {
                for(int i=0;i<=v.size()-3;i++)
                {
                    int dist = abs(v[i]-v[i+1]) + abs(v[i]-v[i+2]) + abs(v[i+1]-v[i+2]);
                    ans = min(ans,dist);
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};