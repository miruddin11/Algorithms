class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        vector<int> freqMap(26,0);
        int diffCount=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i]){
                diffCount+=1;
            }
            freqMap[s1[i]-'a']+=1;
            freqMap[s2[i]-'a']-=1;
        }
        int zeroCount=count(freqMap.begin(),freqMap.end(),0);
        return (diffCount<=2)&&(zeroCount==26);
    }
};