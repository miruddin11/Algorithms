class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st(word.begin(), word.end());
        int cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(st.count(ch) && st.count(ch -'a' + 'A')) {
                cnt += 1;
            }
        }
        return cnt;
    }
};