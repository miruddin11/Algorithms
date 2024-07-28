class Solution {
public:
    typedef pair<int,int> P;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);
        priority_queue< P,vector<P>, greater<P> > pq;
        pq.push({0,1});
        d1[1]=0;
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(!pq.empty())
        {
            int timePassed=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n&&d2[n]!=INT_MAX){
                return d2[n];
            }
            int div=timePassed/change;
            if(div%2==1){
                timePassed=(div+1)*change;
            }
            for(auto &nbr:adj[node]){
                if(d1[nbr]>timePassed+time){
                    d2[nbr]=d1[nbr];
                    d1[nbr]=timePassed+time;
                    pq.push({timePassed+time,nbr});
                }
                else if(d2[nbr]>timePassed+time&&d1[nbr]!=timePassed+time){
                    d2[nbr]=timePassed+time;
                    pq.push({timePassed+time,nbr});
                }
            }
        }
        return 0;
    }
};