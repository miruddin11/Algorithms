class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int mn=arrays[0].front();
        int mx=arrays[0].back();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int cmn=arrays[i].front();
            int cmx=arrays[i].back();
            ans=max(ans,abs(mx-cmn));
            ans=max(ans,abs(cmx-mn));
            mn=min(cmn,mn);
            mx=max(cmx,mx);
        }
        return ans;
    }
};