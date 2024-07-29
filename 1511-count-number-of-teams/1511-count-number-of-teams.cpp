class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int j=1;j<n-1;j++)
        {
            int lgc=0,lsc=0;
            for(int i=0;i<j;i++)
            {
                if(nums[i]<nums[j]){
                    lsc++;
                }
                else if(nums[i]>nums[j]){
                    lgc++;
                }
            }
            int rgc=0,rsc=0;
            for(int k=j+1;k<n;k++)
            {
                if(nums[k]>nums[j]){
                    rgc++;
                }else if(nums[k]<nums[j]){
                    rsc++;
                }
            }
            ans+=lsc*rgc;
            ans+=lgc*rsc;
        }
        return ans;
    }
};