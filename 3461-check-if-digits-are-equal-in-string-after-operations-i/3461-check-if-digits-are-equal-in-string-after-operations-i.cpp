class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string temp;
            for(int i=0;i<s.size()-1;i++){
                temp.push_back(((s[i]-'0')+(s[i+1]-'0'))%10+'0');
            }
            s=temp;
        }
        return (s[0]==s[1]);
    }
};