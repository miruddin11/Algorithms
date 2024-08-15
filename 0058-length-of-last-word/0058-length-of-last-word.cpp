class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(isalpha(s[i])){
                cnt+=1;
                ans=cnt;
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};