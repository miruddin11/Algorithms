class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n + 1, 1);
        vector<pair<int,int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));
        int jumps = 1;
        for(int i = 0; i < n; i++) {
            int idx = vec[i].second;
            for(int j = idx - 1; j >= max(0, idx - d); j--) {
                if(arr[j] >= arr[idx]) {
                    break;
                }
                dp[idx] = max(dp[idx], 1 + dp[j]);
            }

            for(int j = idx + 1; j <= min(n - 1, idx + d); j++) {
                if(arr[j] >= arr[idx]) {
                    break;
                }
                dp[idx] = max(dp[idx], 1 + dp[j]);
            }
            jumps = max(jumps, dp[idx]);
        }
        return jumps;
    }
};