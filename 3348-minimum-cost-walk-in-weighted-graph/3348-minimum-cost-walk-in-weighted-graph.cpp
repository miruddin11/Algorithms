class DisjointUnionSet {
public:
    DisjointUnionSet(int n) {
        parent.resize(n + 1);
        andk.resize(n + 1, numeric_limits<int>::max());
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int a, int b, int w) {
        int p1 = find(a);
        int p2 = find(b);
        if (p1 == p2) {
            andk[p1] &= w;
            return;
        }
        if (size[p1] > size[p2]) {
            parent[p2] = p1;
            size[p1] += size[p2];
            andk[p1] &= w;
            andk[p1] &= andk[p2];
        } else {
            parent[p1] = p2;
            size[p2] += size[p1];
            andk[p2] &= andk[p1];
            andk[p2] &= w;
        }
    }
    
    int getAndk(int node) {
        return andk[node];
    }

private:
    vector<int> parent;
    vector<int> andk;
    vector<int> size;
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        DisjointUnionSet dsu(n);
        for (auto& it : edges) {
            dsu.unionBySize(it[0], it[1], it[2]);
        }
        vector<int> ans;
        for (auto& it : query) {
            if (dsu.find(it[0]) == dsu.find(it[1])) {
                int par = dsu.find(it[1]);
                if (it[0] == it[1] || dsu.getAndk(par) == numeric_limits<int>::max()) ans.push_back(0);
                else ans.push_back(dsu.getAndk(par));
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
