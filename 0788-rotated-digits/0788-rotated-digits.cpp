class Solution {
public:
    int func(string &s, int idx, bool tight, bool good) {
        if (idx == s.size()) return good;
        int lb = 0;
        int ub = tight ? s[idx] - '0' : 9;
        int ans = 0;
        for (int dig = lb; dig <= ub; dig++) {
            if (dig == 3 || dig == 4 || dig == 7) continue;
            ans += func(s, idx + 1, (tight && dig == ub), (good || dig == 2 || dig == 5 || dig == 6 || dig == 9));
        }
        return ans;
    }
    int rotatedDigits(int n) {
        string s = to_string(n);
        return func(s, 0, 1, 0);
    }
};