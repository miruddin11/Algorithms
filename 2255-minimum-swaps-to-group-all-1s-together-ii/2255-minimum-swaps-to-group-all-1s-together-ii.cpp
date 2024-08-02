class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes=0;
        for(auto &x:nums) if(x==1) totalOnes+=1;
        int maxOnes=0;
        int currOnes=0;
        int i=0,j=0;
        int n=nums.size();
        while(j<2*n)
        {
            if(nums[j%n]){
                currOnes++;
            }
            if(j-i+1>totalOnes){
                currOnes-=nums[i%n];
                i++;
            }
            maxOnes=max(maxOnes,currOnes);
            j++;
        }  
        return totalOnes-maxOnes;
    }
};