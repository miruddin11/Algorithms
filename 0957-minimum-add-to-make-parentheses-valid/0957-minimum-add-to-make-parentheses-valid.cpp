class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto &ch:s)
        {
            if(!st.empty()&&st.top()=='('&&ch==')'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return st.size();
    }
};