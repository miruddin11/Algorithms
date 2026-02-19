class Solution {
public:
    typedef long long ll;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<ll>> ans;
        map<int , ll> diff;
        for(auto &s : segments) {
            diff[s[0]] += s[2];
            diff[s[1]] -= s[2];
        }
        int i = 0;
        for(auto &it : diff) {
            if(diff[i] > 0) {
                ans.push_back({i , it.first , diff[i]});
            }

            diff[it.first] += diff[i];
            i = it.first;
        }
        return ans;
    }
};