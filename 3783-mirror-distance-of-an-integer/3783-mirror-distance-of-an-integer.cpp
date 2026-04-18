class Solution {
public:
    int numReverse(int x) {
        int rev = 0;
        while(x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev = numReverse(n);

        return abs(n - rev);
    }
};