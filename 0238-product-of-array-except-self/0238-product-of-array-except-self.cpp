class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]*pref[i-1];
        }
        long long rp=1;
        vector<int> ans(n);
        for(int i=n-1;i>0;i--){
            ans[i]=pref[i-1]*rp;
            rp*=nums[i];
        }
        ans[0]=rp;
        return ans;
    }
};