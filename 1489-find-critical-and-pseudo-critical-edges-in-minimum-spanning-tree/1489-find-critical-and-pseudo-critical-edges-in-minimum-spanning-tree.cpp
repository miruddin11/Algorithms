class Solution {
public:
    int N;
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
    int kruskul(vector<vector<int>> &edges,int skip,int include){
        parent.resize(N);
        rank.resize(N,1);
        for(int i=0;i<N;i++){
            parent[i]=i;
        }
        int sum=0;
        if(include!=-1){
            int u=edges[include][0],v=edges[include][1],wt=edges[include][2];
            Union(u,v);
            sum+=wt;
        }
        for(int i=0;i<edges.size();i++){
            if(i==skip){
                continue;
            }
            vector<int> edge=edges[i];
            int u=edge[0],v=edge[1],wt=edge[2],idx=edge[3];
            if(find(u)!=find(v)){
                Union(u,v);
                sum+=wt;
            }
        }
        // if by skipping an edge the MST can't be formed as it is not coonected so in that case that is a critical edge too
        for(int i=0;i<N;i++){
            if(find(i)!=find(0)){
                return INT_MAX;
            }
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        auto comp=[&](auto &a,auto &b){
            return a[2]<b[2];
        };
        sort(edges.begin(),edges.end(),comp);
        int MST_WEIGHT=kruskul(edges,-1,-1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for(int i=0;i<edges.size();i++){
            if(kruskul(edges,i,-1)>MST_WEIGHT){
                critical.push_back(edges[i][3]);
            }
            else if(kruskul(edges,-1,i)==MST_WEIGHT){
                pseudoCritical.push_back(edges[i][3]);
            }
        }
        return {critical,pseudoCritical};
    }
};