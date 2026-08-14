class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            int len = 0;
            for(int j = i;j < n; j++) {
                mp[s[j]] += 1;
                if(mp[s[j]]> 2) {
                    break;
                }
                len += 1;
            }
            mx = max(mx, len);
        }
        return mx;
    }
};