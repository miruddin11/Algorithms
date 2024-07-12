class Solution {
public:
    string removeSubstr(string &s,string &t)
    {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty()&&st.top()==t[0]&&s[i]==t[1]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        string maxStr=(x>y)? "ab":"ba";
        string minStr=(x>y)? "ba":"ab";
        int n=s.size();
        int ans=0;
        string temp=removeSubstr(s,maxStr);
        int charsRemoved=(n-temp.size());
        ans=ans+(charsRemoved/2)*max(x,y);
        string str=removeSubstr(temp,minStr);
        charsRemoved=(temp.size()-str.size());
        ans=ans+(charsRemoved/2)*min(x,y);
        return ans;
    }
};