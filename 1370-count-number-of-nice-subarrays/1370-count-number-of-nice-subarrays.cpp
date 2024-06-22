class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int n=nums.size();
        int ans=0,oddCnt=0;
        for(int i=0;i<n;i++)
        {
            oddCnt+=(nums[i]%2);
            ans+=mp[oddCnt-k];
            mp[oddCnt]++;
        }
        return ans;
    }
};