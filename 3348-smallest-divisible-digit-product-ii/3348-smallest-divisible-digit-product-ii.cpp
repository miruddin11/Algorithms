class Solution {
public:
    typedef long long ll;
    string buildString(ll tFactor, int slots) {
        string ans = "";
        for(int val = 9; val >= 2; val--) {
            while(tFactor % val == 0) {
                ans.push_back(char(val + '0'));
                tFactor /= val;
            }
        }
        while(ans.size() < slots) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string smallestNumber(string num, long long t) {
        int len = num.size();
        ll target = t;
        for(int p : {2, 3, 5, 7}) {
            while(target % p == 0) {
                target /= p;
            }
        }

        if(target != 1) {
            return "-1";
        }

        vector<ll> factors(len + 1, t);

        for(int i = 0; i < len; i++) {
            int currD = num[i] - '0';
            if(currD == 0) {
                break;
            }
            factors[i + 1] = factors[i] / gcd(factors[i], (ll)currD);
        }

        if(factors[len] == 1) {
            return num;
        }

        int firstZero = num.find('0');
        int startIdx = len - 1;

        if(firstZero != -1) {
            startIdx = firstZero;
        }

        for(int j = startIdx; j >= 0; j--) {
            ll currNeed = factors[j];
            int remaining = len - j - 1;

            for(int nextD = (num[j] - '0') + 1; nextD <= 9; nextD++) {
                ll updatedNeed = currNeed / gcd(currNeed, (ll)nextD);

                string suff = buildString(updatedNeed, remaining);

                if(suff.size() == remaining) {
                    return num.substr(0, j) + char(nextD + '0') + suff;
                }
            }
        }
        return buildString(t, len + 1);
    }
};