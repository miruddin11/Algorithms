class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int a , int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &swap : allowedSwaps) {
            Union(swap[0] , swap[1]);
        }

        unordered_map<int,unordered_map<int, int>> groups;
        for(int i = 0; i < n; i++) {
            groups[find(i)][source[i]] += 1;
        }

        int dist = 0;
        for(int i = 0; i < n; i++) {
            int root = find(i);
            auto &freqMap = groups[root];
            if(freqMap.count(target[i]) && freqMap[target[i]] > 0) {
                freqMap[target[i]] -= 1;
            } else {
                dist += 1;
            }
        }
        
        return dist;
    }
};