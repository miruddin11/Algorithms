class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int i=0,j=0;
        int n=nums.size();
        int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1==k){
                double avg=sum/(double)k;
                ans=max(ans,avg);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};