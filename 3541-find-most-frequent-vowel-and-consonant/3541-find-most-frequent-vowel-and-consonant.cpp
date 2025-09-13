class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> f(26,0);
        for(auto &ch:s){
            f[ch-'a']+=1;
        }
        int maxVowel=0,maxCons=0;
        for(int i=0;i<26;i++){
            if(i==0||i==4||i==8||i==14||i==20){
                maxVowel=max(maxVowel,f[i]);
            }
            else{
                maxCons=max(maxCons,f[i]);
            }
        }
        return maxVowel+maxCons;
    }
};