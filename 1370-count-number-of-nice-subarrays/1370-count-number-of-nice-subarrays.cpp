class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int oddCnt=0,ans=0,prevcnt=0;
        while(j<n)
        {
            if(nums[j]%2==1){
                oddCnt++;
                prevcnt=0;
            }
            if(oddCnt==k){
                while(oddCnt==k){
                    prevcnt++;
                    if(i<n &&nums[i]%2==1){
                        oddCnt--;
                    }
                    i++;
                }
            }
            ans+=prevcnt;
            j++;
        }
        return ans;
    }
};