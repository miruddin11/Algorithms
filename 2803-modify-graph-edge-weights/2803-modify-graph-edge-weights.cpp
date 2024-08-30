#define ll long long
class Solution {
public:
    const int inf=2e9;
    typedef pair<ll,ll> P;
    ll DIJSKTRA(int n,vector<vector<int>>& edges,int src,int dest)
    {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec:edges){
            if(vec[2]!=-1){
                int u=vec[0];
                int v=vec[1];
                int wt=vec[2];
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<ll> result(n,INT_MAX);
        vector<bool> vis(n,false);
        result[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            ll currDist=pq.top().first;
            ll currNode=pq.top().second;
            pq.pop();
            if(vis[currNode]==true){
                continue;
            }
            vis[currNode]=true;
            for(auto &[nbr,d]:adj[currNode])
            {
                if(currDist+d<result[nbr]){
                    result[nbr]=currDist+d;
                    pq.push({result[nbr],nbr});
                }
            }
        }
        return result[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currDist=DIJSKTRA(n,edges,source,destination);
        if(currDist<target){
            return {};
        }
        bool isMatched=(currDist==target);
        if(isMatched)
        {
            for(auto &edge:edges){
                if(edge[2]==-1){
                    edge[2]=inf;
                }
            }
            return edges;
        }
        for(auto &edge:edges)
        {
            if(edge[2]==-1){
                edge[2]=(isMatched==true)?inf:1;
                if(isMatched!=true)
                {
                    ll newDist=DIJSKTRA(n,edges,source,destination);
                    if(newDist<=target)
                    {
                        isMatched=true;
                        edge[2]+=(target-newDist);
                    }
                }
            }
        }
        if(isMatched==false){
            return {};
        }
        return edges;
    }
};