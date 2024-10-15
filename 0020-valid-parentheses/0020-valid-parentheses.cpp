class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s)
        {
            if(x=='('||x=='{'||x=='[') st.push(x);
            else{
                if(st.empty()){
                    return false;
                }
                else if((x==')'&&st.top()=='(')||(x=='}'&&st.top()=='{')||(x==']'&&st.top()=='[')){
                    st.pop();
                }
                else{
                    return false;
                }
            } 
        }
        return st.empty(); 
    }
};