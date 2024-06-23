class Solution {
public:
    vector<string> ans;
    bool isValid(string &s)
    {
        int cnt=0;
        for(auto &ch:s)
        {
            if(ch=='(') cnt+=1;
            else cnt-=1;
            if(cnt<0) return false;
        }
        return cnt==0;
    }
    void solve(string &curr,int n)
    {
        if(curr.size()==2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return ans;
    }
};