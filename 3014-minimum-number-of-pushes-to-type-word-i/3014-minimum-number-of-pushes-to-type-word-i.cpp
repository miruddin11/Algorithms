class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        int n = len / 8;
        int rem = len % 8;
        int ans = 8 * (n * (n + 1) / 2) + rem * (n + 1);
        return ans;
    }
};