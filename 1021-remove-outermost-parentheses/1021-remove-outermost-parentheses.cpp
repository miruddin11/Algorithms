class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0, i = 0;
        string ans = "";
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == '(') {
                open++;
            } else{
                open--;
                if(open == 0) {
                    for(int k = i + 1; k < j; k++) {
                        ans += s[k];
                    }
                    i = j + 1;
                }
            }
        }
        return ans;
    }
};