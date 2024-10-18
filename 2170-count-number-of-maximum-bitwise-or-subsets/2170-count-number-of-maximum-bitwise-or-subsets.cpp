class Solution {
public:
    int cnt;
    void solve(int idx,int val,vector<int> &nums,int target)
    {
        if(val==target)
        {
            cnt+=1;
        }
        for(int i=idx;i<nums.size();i++)
        {
            solve(i+1,val|nums[i],nums,target);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target=0;
        cnt=0;
        for(auto &x:nums){
            target|=x;
        }
        solve(0,0,nums,target);
        return cnt;
    }
};