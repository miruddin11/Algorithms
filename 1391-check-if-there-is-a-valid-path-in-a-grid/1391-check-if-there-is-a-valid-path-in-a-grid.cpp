class Solution {
public:
    unordered_map<int, vector<vector<int>>> mp = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{0, 1}, {-1, 0}}}
    };
    int n, m;
    bool DFS(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        if(i == n - 1 && j == m - 1) {
            return true;
        }
        visited[i][j] = true;
        for(auto &dir : mp[grid[i][j]]) {
            int new_i = i + dir[0], new_j = j + dir[1];
            if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || visited[new_i][new_j]) {
                continue;
            }
            for(auto &backDir : mp[grid[new_i][new_j]]) {
                int i_ = new_i + backDir[0], j_ = new_j + backDir[1];
                if(i_ == i && j_ == j) {
                    if(DFS(new_i, new_j, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return DFS(0, 0, grid, visited);
    }
};