class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closestSum=1e5;
        for(int k=0;k<n-2;k++){
            int i=k+1,j=n-1;
            while(i<j){
                int currSum=nums[i]+nums[j]+nums[k];
                if(abs(target-currSum)<abs(target-closestSum)){
                    closestSum=currSum;
                }
                if(currSum<target){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return closestSum;
    }
};