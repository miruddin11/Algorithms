class Solution {
public:
    int n, m, N;
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3) {
        if(i == n && j == m && k == N) {
            return dp[i][j][k] = true;
        }
        // s3 is formed still either s1 or s2 is left
        if(k >= N) {
            return dp[i][j][k] = false;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        bool ans = false;
        if(s1[i] == s3[k]) {
            ans = solve(i + 1, j, k + 1, s1, s2, s3);
        }
        if(ans == true) {
            return dp[i][j][k] = true;
        }
        if(s2[j] == s3[k]) {
            ans = solve(i, j + 1, k + 1, s1, s2, s3);
        }

        return dp[i][j][k] =  ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(), m = s2.size(), N = s3.size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(N + 1 , -1)));
        if(n + m != N) {
            return false;
        }
        return solve(0, 0, 0, s1, s2, s3);
    }
};