class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> freq(10, 0);
        for(char ch: num) {
            freq[ch - '0'] += 1;
        }
        string left = "";
        int maxDigremain = -1;
        for(int dig = 9; dig >= 0; dig--) {
            if(dig == 0 && left.empty()) {
                continue;
            }
            while(freq[dig] >=2) {
                left.push_back(dig + '0');
                freq[dig] -= 2;
            }
            if(freq[dig] > 0) {
                maxDigremain = max(maxDigremain, dig);
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if(maxDigremain != -1) {
            return left + to_string(maxDigremain) + right;
        }
        if(left.empty() && right.empty()) {
            return "0";
        }
        return left + right;
    }
};