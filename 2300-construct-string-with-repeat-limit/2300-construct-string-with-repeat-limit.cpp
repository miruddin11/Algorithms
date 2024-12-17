class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> f(26,0);
        for(auto &ch:s) f[ch-'a']+=1;
        string ans="";
        int i=25;
        while(i>=0)
        {
            if(f[i]==0){
                i--;
                continue;
            }
            int freq=min(f[i],repeatLimit);
            char ch=(char)('a'+i);
            ans.append(freq,ch);
            f[i]-=freq;
            if(f[i]>0)
            {
                int j=i-1;
                while(j>=0&&f[j]==0){
                    j--;
                }
                if(j<0){
                    break;
                }
                ans.push_back('a'+j);
                f[j]-=1;
            }
        }
        return ans;
    }
};