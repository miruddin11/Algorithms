class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 4 * min(x, y) + 2 * (x != y) + 2 * z;
        return ans;
    }
};