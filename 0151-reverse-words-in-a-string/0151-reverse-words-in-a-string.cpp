class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string t="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '){
                if(t.size()!=0){
                    temp.push_back(t);
                    t="";
                }
            }
            else{
                t+=s[i];
            }
        }
        if(t.size()!=0){
            temp.push_back(t);
        }
        string ans="";
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans=ans+temp[i]+" ";
        }
        ans.pop_back();
        return ans;
    }
};