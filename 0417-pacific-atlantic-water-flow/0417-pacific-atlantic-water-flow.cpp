class Solution {
public:
    int n,m;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>> q,vector<vector<bool>> &vis)
    {
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto &dir:directions){
                int x_=x+dir[0],y_=y+dir[1];
                if(x_<0||x_>=n||y_<0||y_>=m||vis[x_][y_]==true) continue;
                if(heights[x_][y_]<heights[x][y]) continue; // if the curr heights are smaller so that they can reach the boundaries that are connected to oceans
                vis[x_][y_]=true;
                q.push({x_,y_});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        queue<pair<int,int>> pacificQueue,atlanticQueue;
        vector<vector<bool>> pacificVis(n,vector<bool>(m,false)),atlanticVis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            pacificQueue.push({i,0}); pacificVis[i][0]=true;
            atlanticQueue.push({i,m-1}); atlanticVis[i][m-1]=true;
        }
        for(int j=0;j<m;j++){
            pacificQueue.push({0,j}); pacificVis[0][j]=true;
            atlanticQueue.push({n-1,j}); atlanticVis[n-1][j]=true;
        }
        bfs(heights,pacificQueue,pacificVis);
        bfs(heights,atlanticQueue,atlanticVis);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlanticVis[i][j]==true&&pacificVis[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};