class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, int d, vector<int> &arr) {
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = 1;
        for(int j = i - 1; j >= max(0, i - d); j--) {
            if(arr[j] >= arr[i]) {
                break;
            }
            ans = max(ans, 1 + solve(j, d, arr));
        }

        for(int j = i + 1; j <= min(n - 1, i + d); j++) {
            if(arr[j] >= arr[i]) {
                break;
            }
            ans = max(ans, 1 + solve(j, d, arr));
        }
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n + 1, -1);
        int jumps = 0;
        for(int i = 0; i < n; i++) {
            jumps = max(jumps, solve(i, d, arr));
        }
        return jumps;
    }
};