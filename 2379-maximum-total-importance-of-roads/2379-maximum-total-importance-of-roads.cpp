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
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({Degree[i],i});
        }
        long long ans=0;
        long long val=n;
        while(!pq.empty())
        {
            ans= ans+ val * (long long) pq.top().first;
            pq.pop();
            val--;
        }
        return ans;
    }
};