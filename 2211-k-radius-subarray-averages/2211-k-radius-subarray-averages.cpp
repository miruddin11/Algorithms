class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        vector<int> ans(n,-1);
        long long sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i==2*k){
                long long radius=2*k+1;
                int mid=(i+j)/2;
                ans[mid]=sum/radius;
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};