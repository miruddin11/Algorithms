class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto &x:nums1) mp[x]+=1;
        for(auto &y:nums2)
        {
            if(mp[y]>0){
                ans.push_back(y);
                mp[y]-=1;
            }
        }
        return ans;
    }
};