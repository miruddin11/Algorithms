class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]==0)?-1:1;
            if(mp.find(sum)!=mp.end()){
                maxLen=max(maxLen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};