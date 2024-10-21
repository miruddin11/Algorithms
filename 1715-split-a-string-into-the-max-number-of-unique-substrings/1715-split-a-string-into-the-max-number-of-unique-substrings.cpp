class Solution {
public:
    void solve(string &s,unordered_set<string> &st,int i,int currCnt,int &mxCnt)
    {
        if((currCnt+s.size()-i)<=mxCnt){
            return;
        }
        if(i>=s.size()){
            mxCnt=max(mxCnt,currCnt);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            string t=s.substr(i,j-i+1);
            if(st.find(t)==st.end())
            {
                st.insert(t);
                solve(s,st,j+1,currCnt+1,mxCnt);
                st.erase(t);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int mxCnt=0,currCnt=0;
        solve(s,st,0,currCnt,mxCnt);
        return mxCnt;
    }
};