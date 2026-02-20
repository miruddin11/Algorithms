class Solution {
public:
    string solve(string s) {
        int startPoint = 0;
        int currSum = 0;
        vector<string> specialStrings;
        for(int i = 0; i < s.size(); i++) {
            currSum += (s[i] == '0') ? -1 : 1;

            if(currSum == 0) {
                string inBetween = s.substr(startPoint + 1 , i - 1 - startPoint);
                specialStrings.push_back('1' + solve(inBetween) + '0');
                startPoint = i + 1;
            }
        }
        sort(specialStrings.begin() , specialStrings.end() , greater<string>());
        string ans = "";
        for(string &special : specialStrings) {
            ans = ans + special;
        }
        return ans;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};