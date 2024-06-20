class Solution {
public:
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;
        queue<P> pq;
        pq.push({0,{0,0}});
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;
        while(!pq.empty())
        {
            int d=pq.front().first;
            pair<int,int> node=pq.front().second;
            int x=node.first;
            int y=node.second;
            pq.pop();
            for(auto dir:directions)
            {
                int x_=x+dir[0];
                int y_=y+dir[1];
                int dist=1;
                if(isSafe(x_,y_)&&grid[x_][y_]==0&&d+dist<result[x_][y_])
                {
                    pq.push({d+dist,{x_,y_}});
                    result[x_][y_]=d+dist;
                }
            }
        }
        return result[m-1][n-1]==INT_MAX?-1:result[m-1][n-1]+1;
    }
};