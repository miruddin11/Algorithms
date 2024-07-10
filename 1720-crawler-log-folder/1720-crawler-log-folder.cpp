class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto &s:logs)
        {
            if(s=="../"){
                if(!st.empty()){
                    st.pop();
                }else{
                    continue;
                }
            }
            else if(s=="./"){
                continue;
            }
            else{
                st.push(s);
            }
        }
        return st.size();
    }
};