class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);
            if(st.size()>=part.length())
            {
                stack<char> tempSt=st;
                int j=part.length()-1;
                for(;j>=0;j--)
                {
                    if(tempSt.top()!=part[j]){
                        break;
                    }
                    tempSt.pop();
                }
                if(j==-1){
                    int cnt=part.length();
                    while(cnt>0){
                        st.pop();
                        cnt-=1;
                    }
                }
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};