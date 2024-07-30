class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> st;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'&&!st.empty()&&st.back()=='b'){
                st.pop_back();
                cnt++;
            }else{
                st.push_back(s[i]);
            }
        }
        return cnt;
    }
};