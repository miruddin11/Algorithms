class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        unordered_map<string,int> mp;
        string currState="00000";
        mp[currState]=-1;
        vector<int> vowelCount(5,0); // a e i o u
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'){
                vowelCount[0]=(vowelCount[0]+1)%2;
            }
            else if(s[i]=='e'){
                vowelCount[1]=(vowelCount[1]+1)%2;
            }
            else if(s[i]=='i'){
                vowelCount[2]=(vowelCount[2]+1)%2;
            }
            else if(s[i]=='o'){
                vowelCount[3]=(vowelCount[3]+1)%2;
            }
            else if(s[i]=='u'){
                vowelCount[4]=(vowelCount[4]+1)%2;
            }
            currState="";
            for(int j=0;j<5;j++){
                currState+=to_string(vowelCount[j]);
            }
            if(mp.find(currState)!=mp.end()){
                maxLen=max(maxLen,i-mp[currState]);
            }
            else{
                mp[currState]=i;
            }
        }
        return maxLen;
    }
};