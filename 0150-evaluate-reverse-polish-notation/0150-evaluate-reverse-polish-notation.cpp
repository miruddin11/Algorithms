class Solution {
public:
    int fun(int a,int b,string s)
    {
        if(s=="+") return a+b;
        if(s=="-") return a-b;
        if(s=="*") return a*b;
        if(s=="/") return a/b;

        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &s:tokens)
        {
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(fun(a,b,s));
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};