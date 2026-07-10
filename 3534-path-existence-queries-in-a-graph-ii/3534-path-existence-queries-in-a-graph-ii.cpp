class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> ancestorTable;
    int customUpperBound(vector<pair<int, int>>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(arr[mid].first <= target) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return result;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(begin(arr), end(arr));
        vector<int> nodeToIdx(n);
        for(int i = 0; i < n; i++) {
            int node = arr[i].second;
            nodeToIdx[node] = i;
        }
        rows = n;
        cols = log2(n)+1;
        ancestorTable.resize(rows, vector<int>(cols, 0));
        for(int node = 0; node < n; node++) {
            int farthestIdxOneHop = customUpperBound(arr, arr[node].first + maxDiff);
            ancestorTable[node][0] = farthestIdxOneHop;
        }
        for(int j = 1; j < cols; j++) { 
            for(int node = 0; node < n; node++) { 
                ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
            }
        }
        vector<int> result;
        for(auto &query : queries) { 
            int u = query[0];
            int v = query[1];
            int a = nodeToIdx[u];
            int b = nodeToIdx[v];
            if(a == b) {
                result.push_back(0);
                continue;
            }
            if(a > b) {
                swap(a, b);
            }
            int curr  = a;
            int jumps = 0;
            for(int j = cols-1; j >= 0; j--) { 
                if(ancestorTable[curr][j] < b) {
                    curr = ancestorTable[curr][j];
                    jumps += (1 << j);
                }
            }
            if(ancestorTable[curr][0] >= b) {
                result.push_back(jumps+1);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};