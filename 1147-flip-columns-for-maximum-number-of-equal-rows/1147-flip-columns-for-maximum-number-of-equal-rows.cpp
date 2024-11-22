class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        for(auto &row:matrix)
        {
            string s="";
            int startVal=row[0];
            for(auto &val:row)
            {
                s+=(startVal==val)?'S':'B';
            }
            mp[s]+=1;
        }
        int ans=0;
        for(auto &it:mp)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
};