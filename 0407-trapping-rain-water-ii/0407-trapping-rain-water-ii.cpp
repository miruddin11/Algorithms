class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        priority_queue<P,vector<P>,greater<>> cell;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        //left and right side boundary cell
        for(int i=0;i<n;i++){
            cell.push({heightMap[i][0],{i,0}});
            cell.push({heightMap[i][m-1],{i,m-1}});
            visited[i][0]=true,visited[i][m-1]=true;
        }
        //bottom and lower boundary cell
        for(int j=0;j<m;j++){
            cell.push({heightMap[0][j],{0,j}});
            cell.push({heightMap[n-1][j],{n-1,j}});
            visited[0][j]=true,visited[n-1][j]=true;
        }
        int trapWater=0;
        while(!cell.empty()){
            P t=cell.top();
            cell.pop();
            int height=t.first;
            int i=t.second.first,j=t.second.second;
            for(auto &vec:direction){
                int nI=i+vec[0];
                int nJ=j+vec[1];
                if(nI>=0&&nI<n&&nJ>=0&&nJ<m&&visited[nI][nJ]==false){
                    trapWater+=max((height-heightMap[nI][nJ]),0);
                    cell.push({max(height,heightMap[nI][nJ]),{nI,nJ}});
                    visited[nI][nJ]=true;
                }
            }
        }
        return trapWater;
    }
};