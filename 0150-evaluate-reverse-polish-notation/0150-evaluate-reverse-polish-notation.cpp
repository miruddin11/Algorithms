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
        stack<string> st;
        for(auto &s:tokens)
        {
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                st.push(to_string(fun(a,b,s)));
            }
            else{
                st.push(s);
            }
        }
        return stoi(st.top());
    }
};