class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto &x:s)
        {
            if(x=='['){
                st.push(x);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};