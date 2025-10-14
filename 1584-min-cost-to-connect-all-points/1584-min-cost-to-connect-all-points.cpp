class Solution {
public:
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]+=1;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2=points[j][0],y2=points[j][1];
                int cost=abs(x2-x1)+abs(y2-y1);
                edges.push_back({i,j,cost});
            }
        }
        auto comp=[&](auto &a,auto &b){
            return a[2]<b[2];
        };
        sort(edges.begin(),edges.end(),comp);
        int minCost=0;
        for(auto &e:edges){
            int u=e[0],v=e[1],cost=e[2];
            if(find(u)!=find(v)){
                Union(u,v);
                minCost+=cost;
            }
        }
        return minCost;
    }
};