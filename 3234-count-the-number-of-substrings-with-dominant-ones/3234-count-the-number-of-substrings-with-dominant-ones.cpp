class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> countOne(n, 0);
        countOne[0] = (s[0] == '1') ? 1 : 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == '1'){
                countOne[i] = countOne[i-1] + 1;
            }
            else{
                countOne[i] = countOne[i-1];
            }
        }
        int noOfStrings = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int countOfOne  = countOne[j] - (i - 1 >= 0 ? countOne[i-1] : 0);
                int countOfZero = (j - i + 1) - countOfOne;
                if((countOfZero * countOfZero) > countOfOne) {
                    int wasteIndices = (countOfZero * countOfZero) - countOfOne;
                    j += wasteIndices - 1;
                } 
                else if((countOfZero * countOfZero) == countOfOne) {
                    noOfStrings += 1;
                } 
                else { 
                    noOfStrings += 1;
                    int k = sqrt(countOfOne) - countOfZero;
                    int next = j + k;
                    if(next >= n) { 
                        noOfStrings += (n - j - 1);
                        break;
                    }
                    else {
                        noOfStrings += k;
                    }
                    j = next;
                }
            }
        }
        return noOfStrings;
    }
};