class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        dist[0][0] = grid[0][0];
        while(!dq.empty()) {
            int x = dq.front().first, y = dq.front().second;
            dq.pop_front();
            if(x == n - 1 && y == m - 1) {
                return dist[x][y] < health;
            }

            for(auto &d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                int val = grid[nx][ny];
                if(dist[x][y] + val < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + val;

                    if(val == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1] < health;
    }
};