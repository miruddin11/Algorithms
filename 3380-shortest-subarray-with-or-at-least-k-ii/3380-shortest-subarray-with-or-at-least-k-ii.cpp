class Solution {
public:
    void update(int x,vector<int> &vec,int val)
    {
        for(int i=0;i<32;i++)
        {
            if((x>>i)&1){
                vec[i]+=val;
            }
        }
    }
    int getDecimal(vector<int> &vec)
    {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(vec[i]>0)
            {
                ans|=(1<<i);
            }
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        vector<int> vec(32,0);
        int len=INT_MAX;
        while(j<n)
        {
            update(nums[j],vec,1);
            while(i<=j&&getDecimal(vec)>=k)
            {
                len=min(len,j-i+1);
                update(nums[i],vec,-1);
                i++;
            }
            j++;
        }
        return len==INT_MAX?-1:len;
    }
};