class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum=0;
        for(auto &x:nums) totalSum+=x;
        int n=nums.size(),count=0;
        long long leftSum=0;
        for(int i=0;i<n-1;i++)
        {
            leftSum+=nums[i];
            long long rightSum=totalSum-leftSum;
            if(leftSum>=rightSum){
                count+=1;
            }
        }
        return count;
    }
};