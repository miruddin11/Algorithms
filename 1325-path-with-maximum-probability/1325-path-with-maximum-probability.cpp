class Solution {
public:
    typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<P> pq;
        vector<double> ans(n,0);
        pq.push({1,start_node});
        ans[start_node]=1;
        while(!pq.empty())
        {
            int currNode=pq.top().second;
            double currProb=pq.top().first;
            pq.pop();
            for(auto &nbr:adj[currNode])
            {
                double adjProb=nbr.second;
                int adjNode=nbr.first;
                if(ans[adjNode]<currProb*adjProb){
                    ans[adjNode]=currProb*adjProb;
                    pq.push({ans[adjNode],adjNode});
                }
            }
        }
        return ans[end_node];
    }
};