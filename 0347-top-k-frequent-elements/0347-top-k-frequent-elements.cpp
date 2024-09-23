class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &x:nums) mp[x]++;
        vector<pair<int,int>> p;
        for(auto &x:mp)
        {
            p.push_back({x.second,x.first});
        }
        sort(p.rbegin(),p.rend());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(p[i].second);
        }
        return ans;
    }
};