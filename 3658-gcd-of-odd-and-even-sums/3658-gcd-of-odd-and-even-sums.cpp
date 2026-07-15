class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n; // n^2
        int sumEven = sumOdd + n; // n^2 + n => n * (n + 1)
        return gcd(sumOdd, sumEven); // it will be always n
    }
};