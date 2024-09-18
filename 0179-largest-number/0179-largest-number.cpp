class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto &x:nums)
        {
            s.push_back(to_string(x));
        }
        auto comp=[&](string &s,string &t){
            if(s.size()==t.size()) return s>t;
            return s+t>t+s;
        };
        sort(s.begin(),s.end(),comp);
        string ans="";
        for(auto &str:s){
            ans+=str;
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};