class Solution {
public:
    vector<int> rank,parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x),y_parent=find(y);
        if(x_parent==y_parent){
            return;
        }

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]+=1;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        auto comp=[&](auto &a,auto &b){
            return a[2]<b[2];
        };
        sort(edgeList.begin(),edgeList.end(),comp);
        int m=queries.size();
        for(int i=0;i<m;i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        vector<bool> ans(m,false);
        int i=0,len=edgeList.size();
        for(int j=0;j<m;j++){
            int limit=queries[j][2];
            while(i<len&&edgeList[i][2]<limit){
                int u=edgeList[i][0],v=edgeList[i][1];
                Union(u,v);
                i+=1;
            }
            if(find(queries[j][0])==find(queries[j][1])){
                ans[queries[j][3]]=true;
            }
        }
        return ans;
    }
};