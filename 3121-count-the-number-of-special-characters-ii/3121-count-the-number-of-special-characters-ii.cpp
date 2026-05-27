class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> mpl(26, -1), mpu(26, -1);
        int cnt = 0, n = word.size();
        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z') {
                mpl[ch - 'a'] = i;
            } else {
                if(mpu[ch - 'A'] != -1) {
                    continue;
                } else {
                    mpu[ch - 'A'] = i;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(mpl[i] != -1 && mpu[i] != -1) {
                if(mpl[i] < mpu[i]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};