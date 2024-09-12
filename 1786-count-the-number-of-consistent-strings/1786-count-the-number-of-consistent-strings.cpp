class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto &x:allowed) st.insert(x);
        int cnt=0;
        for(auto &s:words)
        {
            bool flag=true;
            for(auto &ch:s)
            {
                if(st.count(ch)==0){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};