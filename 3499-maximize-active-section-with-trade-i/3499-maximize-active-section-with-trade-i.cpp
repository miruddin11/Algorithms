class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int oneCnt = 0;
        for (auto &ch : s) {
            if (ch == '1') oneCnt++;
        }
        int left = 0, right = n - 1;
        while (left < n && s[left] == '1') {
            left++;
        }
        while (right >= 0 && s[right] == '1') {
            right--;
        }
        if (left > right) {
            return oneCnt;
        }
        vector<pair<int, char>> vec;
        int length = 1;
        for (int i = left + 1; i <= right; i++) {
            if (s[i] == s[i - 1]) {
                length++;
            } else {
                vec.push_back({length, s[i - 1]});
                length = 1;
            }
        }
        vec.push_back({length, s[right]});
        int maximum = 0;
        for (int i = 0; i + 2 < vec.size(); i += 2) {
            int range = vec[i].first + vec[i + 2].first;
            maximum = max(maximum, range);
        }
        return oneCnt + maximum;
    }
};