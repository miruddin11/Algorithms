class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        int n=names.size();
        for(int i=0;i<n;i++)
        {
            mp[heights[i]]=names[i];
        }
        int i=n-1;
        for(auto &it:mp){
            names[i]=it.second;
            i--;
        }
        return names;
    }
};