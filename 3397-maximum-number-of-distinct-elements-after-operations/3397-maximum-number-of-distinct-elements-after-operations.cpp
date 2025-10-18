class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int prev=INT_MIN;//stores the last updated value
        int count=0;
        for(int i=0;i<n;i++){
            int minVal=nums[i]-k;
            if(prev<minVal){
                // it means that we can put the smallest value here no collision
                prev=minVal;
                count++;
            }
            else if(prev<nums[i]+k){
                // the minVal must have been seen before 
                //so we can check the max range i.e [nums[i]-k to nums[i]+k] 
                //so that just assign +1 more than prev
                prev=prev+1;
                count++;
            }
        }
        return count;
    }
};