class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size() != s.size()) {
            return false;
        }
        string str = s + s;
        if(str.find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};