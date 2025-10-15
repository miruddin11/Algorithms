class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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
};