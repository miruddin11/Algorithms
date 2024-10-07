class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto &x:s)
        {
            if(!st.empty()&&( (st.top()=='A'&&x=='B') || (st.top()=='C'&&x=='D') ) ){
                st.pop();
            }
            else{
                st.push(x);
            }
        }   
        return st.size();
    }
};