class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]*pref[i-1];
        }
        int rp=1;
        for(int i=n-1;i>0;i--){
            pref[i]=pref[i-1]*rp;
            rp*=nums[i];
        }
        pref[0]=rp;
        return pref;
    }
};