class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> redAdj, blueAdj;
        for(auto &vec : redEdges) {
            int u = vec[0], v = vec[1];
            redAdj[u].push_back(v);
        }
        for(auto &vec : blueEdges) {
            int u = vec[0], v = vec[1];
            blueAdj[u].push_back(v);
        }
        queue<tuple<int, int, int>> q; // (node, colour, distance)
        // 0 --> red , 1 --> blue
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        vector<vector<int>> visited(n, vector<int>(2, 0));
        visited[0][0] = 1, visited[0][1] = 1;
        vector<int> ans(n, -1);
        ans[0] = 0;
        while(!q.empty()) {
            auto [currNode, color, distance] = q.front();
            q.pop();
            if(ans[currNode] == -1) {
                ans[currNode] = distance;
            }
            if(color == 0) {
                // we arrived by red edge
                for(auto &adjNode : blueAdj[currNode]) {
                    if(visited[adjNode][color] == 0) {
                        q.push({adjNode, 1, distance + 1});
                        visited[adjNode][color] = 1;
                    }
                }
            } else {
                // we arrived by blue edge
                for(auto &adjNode : redAdj[currNode]) {
                    if(visited[adjNode][color] == 0) {
                        q.push({adjNode, 0, distance + 1});
                        visited[adjNode][color] = 1;
                    }
                }
            }
        }
        return ans;
    }
};