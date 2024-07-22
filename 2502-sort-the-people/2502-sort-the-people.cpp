class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector< pair<int,string> > mp;
        for(int i=0;i<n;i++){
            mp.push_back({heights[i],names[i]});
        }
        sort(mp.rbegin(),mp.rend());
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=mp[i].second;
        }
        return ans;
    }
};