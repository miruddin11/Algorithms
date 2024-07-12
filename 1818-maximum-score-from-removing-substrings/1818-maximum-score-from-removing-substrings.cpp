class Solution {
public:
    string removeSubstr(string &s,string &matchStr)
    {
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            s[i]=s[j];
            i++;
            if(i>=2&&s[i-2]==matchStr[0]&&s[i-1]==matchStr[1]){
                i-=2;
            }
        }
        s.erase(s.begin()+i,s.end());
        return s;
    }
    int maximumGain(string s, int x, int y) {
        string maxStr=(x>y)? "ab":"ba";
        string minStr=(x<y)? "ab":"ba";
        int n=s.size();
        int ans=0;
        string temp=removeSubstr(s,maxStr);
        int L=temp.size();
        int charsRemoved=(n-L);
        ans=ans+(charsRemoved/2)*max(x,y);
        string str=removeSubstr(temp,minStr);
        charsRemoved=(L-str.size());
        ans=ans+(charsRemoved/2)*min(x,y);
        return ans;
    }
};