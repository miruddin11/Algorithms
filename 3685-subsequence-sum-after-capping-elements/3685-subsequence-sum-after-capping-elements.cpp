class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        vector<bool> result,dp(k+1,false);
        dp[0]=true;
        int n=nums.size();
        for(int cap=1;cap<=n;cap++){
            int largerThanCap=0;
            for(auto &num:nums){
                if(num<cap){
                    continue;
                }
                if(num>cap){
                    largerThanCap++;
                    continue;
                }
                for(int i=k;i>=num;i--){
                    dp[i]=(dp[i]||dp[i-num]);
                }
            }
            bool position=false;
            for(int i=k;i>=max(k-cap*largerThanCap,0);i-=cap){
                position=(position||dp[i]);
            }
            result.push_back(position);
        }
        return result;
    }
};