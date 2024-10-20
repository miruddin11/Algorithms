class Solution {
public:
    char solve(vector<char> &v,char op)
    {
        if(op=='!') return v[0]=='t'?'f':'t';
        else if(op=='&') return count(v.begin(),v.end(),'f')>=1?'f':'t';
        else return count(v.begin(),v.end(),'t')>=1?'t':'f';
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n=expression.size();
        for(int i=0;i<n;i++)
        {
            if(expression[i]==',') continue;

            if(expression[i]==')')
            {
                vector<char> val;
                while(!st.empty()&&st.top()!='(')
                {
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.push(solve(val,op));
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top()=='t'?true:false;
    }
};