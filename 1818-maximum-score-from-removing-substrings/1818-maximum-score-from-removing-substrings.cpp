class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int points=0;
        if(y>x)
        {
            stack<char> st;
            for(int i=0;i<n;i++)
            {
                char curr=s[i];
                if(!st.empty()&&st.top()=='b'&&curr=='a'){
                    points+=y;
                    st.pop();
                }
                else{
                    st.push(curr);
                }
            }
            string temp;
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            for(int i=temp.size()-1;i>=0;i--)
            {
                char curr=temp[i];
                if(!st.empty()&&st.top()=='a'&&curr=='b'){
                    points+=x;
                    st.pop();
                }
                else{
                    st.push(curr);
                }
            }
        }
        else
        {
            stack<char> st;
            for(int i=0;i<n;i++)
            {
                char curr=s[i];
                if(!st.empty()&&st.top()=='a'&&curr=='b'){
                    points+=x;
                    st.pop();
                }
                else{
                    st.push(curr);
                }
            }
            string temp;
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            for(int i=temp.size()-1;i>=0;i--)
            {
                char curr=temp[i];
                if(!st.empty()&&st.top()=='b'&&curr=='a'){
                    points+=y;
                    st.pop();
                }
                else{
                    st.push(curr);
                }
            }
        }

        return points;
    }
};