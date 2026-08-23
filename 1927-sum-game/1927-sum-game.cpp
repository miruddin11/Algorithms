class Solution {
public:
    double getExpectation(char c) {
        return c == '?' ? 4.5 : c - '0';
    }
    bool sumGame(string num) {
        int n = num.length();
        double ans = 0.0;
        for (int i = 0; i < n / 2; ++i) {
            ans += getExpectation(num[i]);
        }
        for (int i = n / 2; i < n; ++i) {
            ans -= getExpectation(num[i]);
        }
        return ans != 0.0;
    }
};