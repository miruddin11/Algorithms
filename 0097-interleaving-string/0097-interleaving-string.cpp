class Solution {
public:
    int n, m, N;
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, string &s1, string &s2, string &s3) {
        if(i == n && j == m && i + j == N) {
            return dp[i][j][i + j] = true;
        }
        // s3 is formed still either s1 or s2 is left
        if(i + j >= N) {
            return dp[i][j][i + j] = false;
        }
        if(dp[i][j][i + j] != -1) {
            return dp[i][j][i + j];
        }
        bool ans = false;
        if(s1[i] == s3[i + j]) {
            ans = solve(i + 1, j, s1, s2, s3);
        }
        if(ans == true) {
            return dp[i][j][i + j] = true;
        }
        if(s2[j] == s3[i + j]) {
            ans = solve(i, j + 1, s1, s2, s3);
        }

        return dp[i][j][i + j] =  ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size(), m = s2.size(), N = s3.size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(N + 1 , -1)));
        if(n + m != N) {
            return false;
        }
        return solve(0, 0, s1, s2, s3);
    }
};