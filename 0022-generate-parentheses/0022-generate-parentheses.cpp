class Solution {
public:
    vector<string> ans;
    void solve(string &curr,int n,int open,int close)
    {
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }
        if(close<open)
        {
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int open=0,close=0;
        solve(curr,n,open,close);
        return ans;
    }
};