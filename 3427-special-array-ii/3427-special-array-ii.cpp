class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> cummSum(n,0);
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2==nums[i-1]%2){
                cummSum[i]=cummSum[i-1]+1;
            }
            else{
                cummSum[i]=cummSum[i-1];
            }
        }  
        int m=queries.size();
        vector<bool> ans(m,false);
        for(int i=0;i<m;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            if(cummSum[end]-cummSum[start]==0){
                ans[i]=true;
            }
        }
        return ans;
    }
};