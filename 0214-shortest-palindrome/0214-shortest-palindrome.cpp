class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=0;i<n;i++)
        {
            if(memcmp(s.c_str(),t.c_str()+i,n-i)==0){
                return t.substr(0,i)+s;
            }
        }
        return s+s;
    }
};