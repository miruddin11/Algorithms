class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++)
        {
            string s=details[i].substr(11,2);
            int val=stoi(s);
            if(val>60) cnt++;
        }
        return cnt;
    }
};