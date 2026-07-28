class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char &ch : s) {
            freq[ch - 'a'] += 1;
        }
        string left = "";
        char single = '@';
        for(int i = 0; i < 26; i++) {
            char ch = i + 'a';
            left += string(freq[i] / 2, ch);
            if(freq[i] % 2 == 1) {
                single = ch;
            }
        }
        string right = left;
        reverse(begin(right), end(right));
        if(single == '@') {
            return left + right;
        } else {
            return left + single + right;
        }
    }
};