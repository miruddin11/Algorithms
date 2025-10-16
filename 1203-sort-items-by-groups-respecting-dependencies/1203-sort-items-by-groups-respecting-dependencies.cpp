class Solution {
public:
    vector<int> topoSort(unordered_map<int,vector<int>> &adj,vector<int> &inDegree){
        vector<int> order;
        queue<int> q;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            order.push_back(u);
            for(auto &v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        return (adj.size()==order.size())?order:vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //group assigning to those who have -1 as their group
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }
        //create itemGraph and also the itemIndegree
        unordered_map<int,vector<int>> itemGraph;
        vector<int> itemIndegree(n,0);
        //create groupGraph and the groupIndegree
        unordered_map<int,vector<int>> groupGraph;
        vector<int> groupIndegree(m,0);
        // filling those graphs and indegrees
        for(int i=0;i<n;i++){
            for(auto &prev:beforeItems[i]){
                // from these beforeItems we can reach to that items
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                if(group[i]!=group[prev]){
                    int prevItemGroup=group[prev];
                    int currItemGroup=group[i];
                    groupGraph[prevItemGroup].push_back(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }
            }
        }
        vector<int> itemOrder=topoSort(itemGraph,itemIndegree);
        vector<int> groupOrder=topoSort(groupGraph,groupIndegree);
        unordered_map<int,vector<int>> groupToitemsInorder;
        for(auto &item:itemOrder){
            int itemGroup=group[item];
            groupToitemsInorder[itemGroup].push_back(item);
        }
        vector<int> ans;
        for(auto &group:groupOrder){
            for(auto &v:groupToitemsInorder[group]){
                ans.push_back(v);
            }
        }
        return ans;
    }
};