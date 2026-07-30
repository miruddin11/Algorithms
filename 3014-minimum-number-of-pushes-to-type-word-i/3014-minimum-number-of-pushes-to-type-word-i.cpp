class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        for(int i = 0; i < word.size(); i++) {
            int press = (i / 8) + 1;
            ans = ans + press;
        }
        return ans;
    }
};