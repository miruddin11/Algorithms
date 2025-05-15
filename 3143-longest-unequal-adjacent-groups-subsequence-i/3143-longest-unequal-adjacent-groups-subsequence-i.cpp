class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        int length=0;
        int currgroup=-1;
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(groups[i]!=currgroup){
                ans.push_back(words[i]);
                currgroup=groups[i]+length;
            }
        }
        return ans;
    }
};