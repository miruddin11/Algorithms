class Solution {
public:
    string compressedString(string word) {
        string ans;
        int cnt = 1;
        int n = word.size();
        
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && word[i] == word[i + 1]) {
                cnt++;
            } else {
                while (cnt > 9) {
                    ans += "9";
                    ans += word[i];
                    cnt -= 9;
                }
                ans += to_string(cnt) + word[i];
                cnt = 1;
            }
        }
        return ans;
    }
};
