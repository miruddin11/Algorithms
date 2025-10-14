class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<=n-2*k;i++){
            bool f1=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j-1]>=nums[j]){
                    f1=false;
                    break;
                }
            }
            bool f2=true;
            for(int j=i+k+1;j<i+2*k;j++){
                if(nums[j-1]>=nums[j]){
                    f2=false;
                    break;
                }
            }
            if(f1==true&&f2==true){
                return true;
            }
        }
        return false;
    }
};