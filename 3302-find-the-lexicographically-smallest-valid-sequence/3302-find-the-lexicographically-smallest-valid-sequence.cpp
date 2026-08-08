class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int r = m - 1, c = 0;
        vector<int> right(n);
        for(int i = n - 1; i >= 0; i--) {
            right[i] = c;
            if (r >= 0 && word1[i] == word2[r]) {
                r--;
                c++;
            }
        }
        vector<int> res;
        bool flag = false;
        int j = 0;
        for(int i = 0; i < n && j < m; i++) {
            if(word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            } else if(!flag && right[i] >= m - 1 - j) {
                res.push_back(i);
                j++;
                flag = true;
            }
        }
        if(j == m) {
            return res;
        }
        return {};
    }
};