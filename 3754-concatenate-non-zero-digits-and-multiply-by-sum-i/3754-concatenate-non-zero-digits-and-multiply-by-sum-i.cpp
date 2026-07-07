class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll x = 0, sum = 0;
        for(auto &ch : to_string(n)) {
            if(ch != '0') {
                x = x * 10 + (ch - '0');
                sum += (ch - '0');
            }
        }
        return x * sum;
    }
};