class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x=find(x),parent_y=find(y);
        if(parent_x==parent_y){
            return;
        }
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]+=1;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        rank.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<int,vector<int>> adj;
        for(auto &vec:edges){
            int u=vec[0],v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>> valToNodes;
        for(int i=0;i<n;i++){
            int val=vals[i];
            valToNodes[val].push_back(i);
        }
        vector<bool> isActive(n,false);
        int ans=n;
        for(auto &it:valToNodes){
            vector<int> nodes=it.second;
            for(auto &u:nodes){
                for(auto &v:adj[u]){
                    if(isActive[v]){
                        Union(u,v);
                    }
                }
                isActive[u]=true;
            }
            vector<int> allParent;
            for(auto &u:nodes){
                int parentIs=find(u);
                allParent.push_back(parentIs);
            }
            sort(allParent.begin(),allParent.end());
            int sz=allParent.size();
            for(int i=0;i<sz;){
                long long count=0;
                int currParent=allParent[i];
                while(i<sz&&currParent==allParent[i]){
                    count++;
                    i++;
                }
                int formula=(count*(count-1)/2);
                ans=ans+formula;
            }
        }
        return ans;
    }
};