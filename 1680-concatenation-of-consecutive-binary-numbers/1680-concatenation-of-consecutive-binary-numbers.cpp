class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long result = 0;
        for(int i = 1; i<=n; i++) {
            int digits = log2(i) + 1;
            result = (((result << digits)%mod) + i)%mod;
        }
        return result; 
    }
};