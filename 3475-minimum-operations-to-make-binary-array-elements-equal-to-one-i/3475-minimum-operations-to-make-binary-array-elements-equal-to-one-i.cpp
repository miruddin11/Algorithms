class Solution {
public:
    int minOperations(vector<int>& nums) {
        int j=0,cnt=0;
        while(j<nums.size())
        {
            if(nums[j]==0){
                if(j+2>=nums.size()){
                    return -1;
                }
                nums[j]=1;
                nums[j+1]=(nums[j+1]==0)?1:0;
                nums[j+2]=(nums[j+2]==0)?1:0;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};