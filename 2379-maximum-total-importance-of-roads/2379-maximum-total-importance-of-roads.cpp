class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> Degree(n,0);
        for(auto &e:roads)
        {
            int u=e[0],v=e[1];
            Degree[u]++;
            Degree[v]++;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({Degree[i],i});
        }
        sort(v.rbegin(),v.rend());
        vector<int> values(n,0);
        for(int i=0;i<v.size();i++)
        {
            values[v[i].second]=n-i;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans =ans + (long long) Degree[i] * (long long) values[i];
        }
        return ans;
    }
};