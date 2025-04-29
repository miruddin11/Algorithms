class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=1;i<n;i++) maxi=max(maxi,nums[i]);
        return solve(nums,k,maxi);
    }
private:
    long long solve(vector<int>& nums,int k,int maxi)
    {
        int n=nums.size();
        map<int,vector<int>> m;
        long long f=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
            if(m[maxi].size()>=k)
            {
                f+=m[maxi][m[maxi].size()-k]+1;
            }
        }
        return f;
    }
};