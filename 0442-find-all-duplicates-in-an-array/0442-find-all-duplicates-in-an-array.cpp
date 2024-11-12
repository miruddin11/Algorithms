class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //to store the answer
        vector<int> ans;

        //traverse the list
        for(int i=0;i<nums.size();i++)
        {
            //Marking it as Visited using index = abs(nums[i])-1 
            int idx=abs(nums[i])-1;
            //If it is negative then it is already visited
            if(nums[idx]<0){
                ans.push_back(idx+1);
            }
            else{
                //marked visited by adding a negative sign
                nums[idx]=-nums[idx];
            }
        }
        return ans;
    }
};