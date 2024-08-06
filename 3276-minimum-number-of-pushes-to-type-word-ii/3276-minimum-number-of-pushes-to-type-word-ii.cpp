class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26,0);
        for(auto &x:word){
            f[x-'a']++;
        }
        sort(f.rbegin(),f.rend());
        int ans=0;
        for(int i=0;i<26;i++)
        {
            int press=(i/8 +1);
            ans+=press*f[i];
        }
        return ans;
    }
};