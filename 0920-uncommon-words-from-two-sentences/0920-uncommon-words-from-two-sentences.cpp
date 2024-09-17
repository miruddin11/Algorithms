class Solution {
public:
    void makeWord(unordered_map<string,int> &mp,string &t)
    {
        string s="";
        for(auto &ch:t)
        {
            if(ch==' '){
                mp[s]+=1;
                s="";
            }else{
                s+=ch;
            }
        }
        if(!s.empty()){
            mp[s]+=1;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        makeWord(mp,s1);
        makeWord(mp,s2);
        vector<string> ans;
        for(auto &x:mp){
            if(x.second==1) ans.push_back(x.first);
        }
        return ans;
    }
};