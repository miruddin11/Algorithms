class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int> mp;
        for(auto &ch:s) mp[ch]+=1;
        vector<pair<int,char>> vec;
        for(auto &[ch,freq]:mp)
        {
            vec.push_back({freq,ch});
        }
        sort(vec.rbegin(),vec.rend());
        string ans;
        for(auto &[freq,ch]:vec)
        {
            while(freq--){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};