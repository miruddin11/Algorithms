class Solution {
public:
    typedef pair<int,int> P;
    int orangesRotting(vector<vector<int>>& grid) {
        int cntFresh=0;
        queue<P> q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) cntFresh+=1;
            }
        }
        if(cntFresh==0){
            return 0;
        }
        if(q.size()==0){
            return -1;
        }
        vector<P> dir={{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> vis=grid;
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto &[dx,dy]:dir)
                {
                    int r=i+dx;
                    int c=j+dy;
                    if(r>=0&&r<n&&c>=0&&c<m&&vis[r][c]==1){
                        vis[r][c]=2;
                        q.push({r,c});
                        cntFresh-=1;
                    }
                }
            }
            time++;
        }
        if(cntFresh!=0){
            return -1;
        }

        return time-1;
    }
};