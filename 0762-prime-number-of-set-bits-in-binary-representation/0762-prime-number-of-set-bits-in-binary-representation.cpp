class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int N = 32;
        vector<int> isPrime(N + 1 , 1);
        isPrime[0] = 0 , isPrime[1] = 0;
        for(int i = 2; i * i <= N; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= N; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int x = left; x <= right; x++) {
            int setBitCount = __builtin_popcount(x);
            if(isPrime[setBitCount]) {
                cnt += 1;
            }
        }
        return cnt;
    }
};