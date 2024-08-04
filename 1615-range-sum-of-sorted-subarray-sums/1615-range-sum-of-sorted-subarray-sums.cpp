class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        vector<int> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        vector<int> sums;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==0) sums.push_back(pref[j]);
                else sums.push_back(pref[j]-pref[i-1]);
            }
        }
        sort(sums.begin(),sums.end());
        int sum=0;
        for(int i=left-1;i<right;i++){
            sum= (sum%mod+sums[i]%mod)%mod;
        }
        return sum%mod;
    }
};