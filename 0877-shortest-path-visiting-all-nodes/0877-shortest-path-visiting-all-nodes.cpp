class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1||n==0){
            return 0;
        }
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;
        for(int i=0;i<n;i++)
        {
            int maskVal=(1<<i);
            q.push({i,maskVal});
            vis.insert({i,maskVal});
        }
        int allVisited=(1<<n) -1;
        int path=0;
        while(!q.empty())
        {
            int size=q.size();
            path+=1;
            while(size--)
            {
                int currNode=q.front().first;
                int currMask=q.front().second;
                q.pop();
                for(auto &nbr:graph[currNode])
                {
                    int nextMask=currMask|(1<<nbr);
                    if(nextMask==allVisited){
                        return path;
                    }
                    if(vis.find({nbr,nextMask})==vis.end())
                    {
                        vis.insert({nbr,nextMask});
                        q.push({nbr,nextMask});
                    }
                }
            }
        }
        return -1;
    }
};