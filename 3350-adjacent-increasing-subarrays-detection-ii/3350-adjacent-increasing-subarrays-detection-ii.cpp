class Solution {
public:
    bool isIncreasing(vector<int> &nums,int k)
    {
        int currRun=1,prevRun=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                currRun+=1;
            }
            else{
                prevRun=currRun;
                currRun=1;
            }
            if(currRun>=2*k||min(currRun,prevRun)>=k){
                return true;
            }
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n/2;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isIncreasing(nums,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};