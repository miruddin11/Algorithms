class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> rMax(n,0);
        rMax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rMax[i]=max(rMax[i+1],nums[i]);
        }
        int ans=0;
        int i=0,j=0;
        while(j<n)
        {
            while(nums[i]>rMax[j]){
                i+=1;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};