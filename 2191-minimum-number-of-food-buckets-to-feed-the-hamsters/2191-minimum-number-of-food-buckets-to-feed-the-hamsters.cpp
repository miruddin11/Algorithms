class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(hamsters[i]=='H')
            {
                if(i-1>=0&&hamsters[i-1]=='B') continue;
                if(i+1<n&&hamsters[i+1]=='.'){
                    ans++;
                    i+=2;
                    continue;
                }
                if(i-1>=0&&hamsters[i-1]=='.'){
                    ans++;
                    continue;
                }
                return -1;
            }
        }
        return ans;
    }
};