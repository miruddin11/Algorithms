class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                if(!st.empty()) {
                    if(s[st.top()] == '(') {
                        st.pop();
                    } else {
                        st.push(i);
                    }
                } else {
                    st.push(i);
                }
            }
        }
        if(st.empty()){
            maxLen = n; 
        } else {
            int r = n , l = 0;
            while(!st.empty()) {
                int l = st.top();
                st.pop();
                maxLen = max(maxLen , r - l - 1);
                r = l;
            }
            maxLen = max(maxLen , r);
        }
        return maxLen;
    }
};