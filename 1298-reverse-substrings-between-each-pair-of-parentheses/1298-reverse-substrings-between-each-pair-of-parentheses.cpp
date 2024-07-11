class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')'){
                string temp="";
                while(!st.empty()&&st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<temp.size();i++){
                    st.push(temp[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};