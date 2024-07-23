class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto &x:nums){
            mp[x]+=1;
        }
        vector<pair<int,int>> v;// freq element
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        auto comp=[&](auto &a,auto &b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        };
        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(auto &i:v){
            int f=i.first;
            while(f--){
                ans.push_back(i.second);
            }
        }
        return ans;
    }
};