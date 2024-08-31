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
        pq.push({1.0,start_node});
        vector<double> result(n,0.0);
        result[start_node]=1;
        while(!pq.empty())
        {
            double currProb=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            for(auto &nbr:adj[currNode])
            {
                int adjNode=nbr.first;
                double prob=nbr.second;
                if(currProb*prob>result[adjNode]){
                    result[adjNode]=currProb*prob;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }
        return result[end_node];
    }
};