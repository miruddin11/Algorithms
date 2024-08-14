class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int i=0,j=1;
            int pairCount=0;
            while(j<n)
            {
                while(nums[j]-nums[i]>mid){
                    i++;
                }
                pairCount+=(j-i);
                j++;
            }
            if(pairCount<k){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};