class Solution {
public:
    typedef long long ll;
    typedef pair<int,ll> P;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        ll maxCost = 0;
        int n = online.size();
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<P>> adj;
        for(auto &vec : edges) {
            int u = vec[0], v = vec[1];
            ll cost = vec[2];
            adj[u].push_back({v, cost});
            inDegree[v] += 1;
            maxCost = max(cost, maxCost);
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!inDegree[i]) {
                q.push(i);
            } 
        }
        vector<int> order;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(auto &[nbr, cost] : adj[u]) {
                inDegree[nbr] -= 1;
                if(!inDegree[nbr]) {
                    q.push(nbr);
                }
            }
        }
        auto check = [&](ll mid) {
            if(!online[0] || !online[n - 1]) {
                return false;
            }
            vector<ll> dist(n, LLONG_MAX);
            dist[0] = 0;
            for(int u : order) {
                if(dist[u] == LLONG_MAX) {
                    continue;
                }
                if(u != 0 && u != n - 1 && online[u] == false) {
                    continue;
                }

                for(auto &[nbr, cost] : adj[u]) {
                    if(cost < mid) {
                        continue;
                    }
                    if(nbr != n - 1 && online[nbr] == false) {
                        continue;
                    }
                    dist[nbr] = min(dist[nbr], dist[u] + cost);
                }
            }
            return dist[n - 1] <= k;
        };
        ll low = 0, high = maxCost;
        int ans = -1;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(check(mid)) {
                ans = mid;
                low = mid + 1;   
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};