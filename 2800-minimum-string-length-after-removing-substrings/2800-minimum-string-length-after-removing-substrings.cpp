class Solution {
public:
    int minLength(string s) {
        vector<char> st;
        for(auto &x:s)
        {
            if(!st.empty()&&( (st.back()=='A'&&x=='B') || (st.back()=='C'&&x=='D') ) ){
                st.pop_back();
            }
            else{
                st.push_back(x);
            }
        }   
        return st.size();
    }
};