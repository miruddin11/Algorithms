class Solution {
public:
    const int M=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26,0);
        int len=0;
        for(auto &ch:s) mp[ch-'a']+=1;
        for(int i=0;i<t;i++)
        {
            vector<int> t(26,0);
            for(int j=0;j<26;j++)
            {
                char ch=(char)('a'+j);
                int freq=mp[j];
                if(ch=='z'){
                    t[0]=(t[0]+freq)%M;
                    t[1]=(t[1]+freq)%M;
                }
                else{
                    t[ch+1-'a']=(t[ch+1-'a']+freq)%M;;
                }
            }
            mp=move(t);
        }
        for(int i=0;i<26;i++){
            len=(len+mp[i])%M;
        }
        return len;
    }
};