class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i])){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};