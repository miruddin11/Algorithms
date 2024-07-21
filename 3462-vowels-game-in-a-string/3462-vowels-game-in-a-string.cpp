class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    bool doesAliceWin(string s) {
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                return true;
            }
        }
        return false;
    }
};