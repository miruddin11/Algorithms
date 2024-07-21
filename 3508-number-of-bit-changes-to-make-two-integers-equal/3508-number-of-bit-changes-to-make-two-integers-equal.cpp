class Solution {
public:
    int minChanges(int n, int k) {
        int val=n&k;
        if(val==k){
            return __builtin_popcount(n)-__builtin_popcount(k);
        }
        return -1;
    }
};