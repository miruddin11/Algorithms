class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;
        q.push({entrance[0], entrance[1]});
        vis.insert({entrance[0], entrance[1]});
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) &&
                    !(entrance[0] == x && entrance[1] == y)) {
                    return steps;
                }
                for (auto& dir : direction) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                        vis.count({nx, ny}) > 0 || maze[nx][ny] == '+')
                        continue;
                    q.push({nx, ny});
                    vis.insert({nx, ny});
                }
            }
            steps++;
        }
        return -1;
    }
};