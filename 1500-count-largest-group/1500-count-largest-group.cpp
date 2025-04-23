class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxSize=0;
        for(int i=1;i<=n;i++)
        {
            int Dsum=0;
            int x=i;
            while(x>0){
                Dsum+=(x%10);
                x/=10;
            }
            mp[Dsum]+=1;
            maxSize=max(maxSize,mp[Dsum]);
        }
        int count=0;
        for(auto &it:mp)
        {
            if(it.second==maxSize) count++;
        }
        return count;
    }
};