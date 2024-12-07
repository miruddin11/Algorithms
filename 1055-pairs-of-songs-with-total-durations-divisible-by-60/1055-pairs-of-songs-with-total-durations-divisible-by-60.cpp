class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60,0);
        int n=time.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int a=time[i]%60;
            if(a==0) cnt+=v[0];
            else cnt+=v[60-a];
            v[a]+=1;
        }
        return cnt;
    }
};