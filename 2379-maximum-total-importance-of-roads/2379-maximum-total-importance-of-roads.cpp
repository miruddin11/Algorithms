class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> Degree(n,0);
        for(auto &e:roads)
        {
            int u=e[0],v=e[1];
            Degree[u]++;
            Degree[v]++;
        }
        sort(Degree.begin(),Degree.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans= ans+ (long long)Degree[i]* (long long)(i+1);
        }
        return ans;
    }
};