class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(char &ch : s) {
            if(ch == '*') {
                if(!ans.empty()) {
                    ans.pop_back();
                } else {
                    continue;
                }
            } else if(ch == '#') {
                ans = ans + ans;
            } else if(ch == '%') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};