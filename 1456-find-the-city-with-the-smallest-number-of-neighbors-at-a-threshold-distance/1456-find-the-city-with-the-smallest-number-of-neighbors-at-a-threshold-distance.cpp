class Solution {
public:
    int Dijasktra(unordered_map< int, vector< pair<int,int> > > &adj,int distanceThreshold,int source,int n)
    {
        vector<int> result(n,INT_MAX);
        priority_queue<pair<int,int>> pq;
        pq.push({0,source});//distance node
        result[source]=0;
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node]){
                int adjNode=vec.first;
                int d=vec.second;
                if(d+dis<result[adjNode]){
                    result[adjNode]=d+dis;
                    pq.push({d+dis,adjNode});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(result[i]<=distanceThreshold){
                cnt+=1;
            }
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map< int, vector< pair<int,int> > > adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int ans=-1;
        int cnt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int val=Dijasktra(adj,distanceThreshold,i,n);
            if(cnt>val){
                cnt=val;
                ans=i;
            }
            else if(cnt==val){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};