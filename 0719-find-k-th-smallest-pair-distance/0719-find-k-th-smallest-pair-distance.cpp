class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> D(mx+1,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                D[abs(nums[i]-nums[j])]+=1;
            }
        }
        for(int i=0;i<D.size();i++)
        {
            k-=D[i];
            if(k<=0){
                return i;
            }
        }
        return -1;
    }
};