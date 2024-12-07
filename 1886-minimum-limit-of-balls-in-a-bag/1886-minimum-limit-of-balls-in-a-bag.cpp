class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        auto solve=[&](int mid){
            int totalOperation=0;
            for(int i=0;i<n;i++)
            {
                int op=(nums[i]/mid);
                if(nums[i]%mid==0){
                    op-=1;
                }
                totalOperation+=op;
            }
            return (totalOperation<=maxOperations);
        };
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};