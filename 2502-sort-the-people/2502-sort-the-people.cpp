class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=names.size();
        vector< pair<int,string> > mp(n);
        for(int i=0;i<n;i++){
            mp[i]={heights[i],names[i]};
        }
        sort(mp.begin(),mp.end());
        for(int i=n-1;i>=0;i--){
            names[i]=mp[n-i-1].second;
        }
        return names;
    }
};