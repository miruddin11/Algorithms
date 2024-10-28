class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mxLen=0;
        unordered_map<int,int> mp;
        for(auto &x:nums)
        {
            int sq=sqrt(x);
            if(sq*sq==x&&mp.find(sq)!=mp.end())
            {
                mp[x]=1+mp[sq];
            }
            else{
                mp[x]=1;
            }
            mxLen=max(mxLen,mp[x]);
        }
        return mxLen<2?-1:mxLen;
    }
};