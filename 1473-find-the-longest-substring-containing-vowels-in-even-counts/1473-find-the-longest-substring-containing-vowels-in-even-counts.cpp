class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        unordered_map<int,int> mp;
        int mask=0;
        mp[mask]=-1;
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'){
                mask^=1;
            }
            else if(s[i]=='e'){
                mask^=2;
            }
            else if(s[i]=='i'){
                mask^=4;
            }
            else if(s[i]=='o'){
                mask^=8;
            }
            else if(s[i]=='u'){
                mask^=16;
            }
            if(mp.find(mask)!=mp.end()){
                maxLen=max(maxLen,i-mp[mask]);
            }
            else{
                mp[mask]=i;
            }
        }
        return maxLen;
    }
};