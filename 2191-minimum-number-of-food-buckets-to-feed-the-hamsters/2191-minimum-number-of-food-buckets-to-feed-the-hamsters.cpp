class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.size();
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(hamsters[i]=='H')
            {
                if(mp[i-1]>0||mp[i+1]>0) continue;
                if(i!=n-1&&hamsters[i+1]=='.'){
                    ans+=1;
                    mp[i+1]++;
                    continue;
                }
                if(i!=0&&hamsters[i-1]=='.'){
                    ans+=1;
                    continue;
                }
                return -1;
            }
        }
        return ans;
    }
};