class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int n=secret.size();
        int bulls=0;
        string t="";
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                mp[secret[i]]+=1;
                t+=guess[i];
            }
        }
        int cows=0;
        for(int i=0;i<t.size();i++)
        {
            if(mp.find(t[i])!=mp.end()){
                cows++;
                mp[t[i]]--;
                if(mp[t[i]]==0){
                    mp.erase(t[i]);
                }
            }
        }
        string ans=to_string(bulls);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';
        return ans;
    }
};