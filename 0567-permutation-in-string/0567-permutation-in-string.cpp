class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f(26,0);
        for(auto &ch:s1){
            f[ch-'a']+=1;
        }
        int i=0,j=0;
        int k=s1.size();
        int n=s2.size();
        while(j<n)
        {
            f[s2[j]-'a']--;
            if(j-i+1==k){
                int mn=*min_element(begin(f),end(f));
                if(mn==0){
                    return true;
                }
                f[s2[i]-'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};