class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diff(n,0);
        for(auto &vec:shifts)
        {
            int L=vec[0],R=vec[1];
            int x=(vec[2]==1)?1:-1;
            diff[L]+=x;
            if(R+1<n){
                diff[R+1]-=x;
            }
        }
        for(int i=1;i<n;i++)
        {
            diff[i]+=diff[i-1];
        }
        for(int i=0;i<n;i++)
        {
            int shift=diff[i]%26;
            if(shift<0){
                shift+=26;
            }
            s[i]=(((s[i]-'a')+shift)%26)+'a';
        }
        return s;
    }
};