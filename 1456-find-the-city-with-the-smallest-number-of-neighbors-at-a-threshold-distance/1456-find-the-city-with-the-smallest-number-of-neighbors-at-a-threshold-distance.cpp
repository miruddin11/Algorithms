class Solution {
public:
    vector<vector<int>> shortestPathMatrix;
    void Dijasktra(unordered_map< int, vector< pair<int,int> > > &adj,int distanceThreshold,int source,int n)
    {
        vector<int> result(n,INT_MAX);
        priority_queue<pair<int,int>> pq;
        pq.push({0,source});
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
        shortestPathMatrix.push_back(result);
    }
    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
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
        for(int i=0;i<n;i++)
        {
            Dijasktra(adj,distanceThreshold,i,n);
        }
        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};