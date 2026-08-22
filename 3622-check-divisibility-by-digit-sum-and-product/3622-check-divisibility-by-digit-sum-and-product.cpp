class Solution {
public:
    bool checkDivisibility(int n) {
        long long product = 1;
        int sum = 0, x = n;
        while(x > 0) {
            int d = x % 10;
            x = x / 10;
            sum += d;
            product = product * (long long) d;
        }
        return n % (sum + product) == 0;
    }
};