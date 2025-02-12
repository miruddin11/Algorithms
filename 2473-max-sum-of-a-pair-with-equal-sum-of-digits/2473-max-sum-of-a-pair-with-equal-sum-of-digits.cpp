class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxSum=-1;
        for(auto &num:nums)
        {
            int x=num,sum=0;
            while(x!=0)
            {
                sum+=(x%10);
                x/=10;
            }
            if(mp.find(sum)!=mp.end())
            {
                maxSum=max(maxSum,mp[sum]+num);
                mp[sum]=max(mp[sum],num);
            }
            else{
                mp[sum]=num;
            }
        }
        return maxSum;
    }
};