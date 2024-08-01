class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto &s:details)
        {
            int val=10*(s[11]-'0')+(s[12]-'0');
            if(val>60) cnt++;
        }
        return cnt;
    }
};