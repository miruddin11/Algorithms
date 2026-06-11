class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0, j = 0, n = start.size(), m = result.size();
        while(i < n || j < m) {
            while(i < n && start[i] == 'X') {
                i++;
            }
            while(j < m && result[j] == 'X') {
                j++;
            }
            if(i == n && j == n) {
                return true;
            }
            if(i == n || j == m) {
                return false;
            }
            if(start[i] != result[j]) {
                return false;
            }
            if(start[i] == 'L' && i < j) {
                return false;
            }
            if(start[i] == 'R' && i > j) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};