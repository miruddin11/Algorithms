class Solution {
public:
    bool isGood(int num) {
        bool possible = false;
        while(num > 0) {
            int d = (num % 10);
            if(d == 3 || d == 4 || d == 7) {
                return false;
            }
            if(d == 2 || d == 5 || d == 6 || d == 9) {
                possible = true;
            }
            num /= 10;
        }
        return possible;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(isGood(i)) {
                count += 1;
            }
        }
        return count;
    }
};