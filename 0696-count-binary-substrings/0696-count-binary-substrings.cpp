class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int prev = 0 , curr = 1;
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                curr += 1;
            } else {
                count += min(curr , prev);
                prev = curr;
                curr = 1;
            }
        }
        count += min(curr , prev);
        return count;
    }
};