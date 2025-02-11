class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(s[i]);
            if(ans.size()>=part.size())
            {
                int m=ans.size();
                if(ans.substr(m-part.size())==part){
                    ans.erase(m-part.size());
                }
            }
        }
        return ans;
    }
};