class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'&&!st.empty()&&st.top()=='b'){
                st.pop();
                cnt++;
            }else{
                st.push(s[i]);
            }
        }
        return cnt;
    }
};