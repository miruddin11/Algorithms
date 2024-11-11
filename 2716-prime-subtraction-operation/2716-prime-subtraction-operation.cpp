class Solution {
public:
    bool isPrime[1001];
    void seive()
    {
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<1001;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<1001;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        memset(isPrime,true,sizeof(isPrime));
        seive();
        int n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i]){
                continue;
            }
            for(int p=2;p<nums[i];p++)
            {
                if(!isPrime[p]){
                    continue;
                }
                if(nums[i]-p<nums[i+1]){
                    nums[i]-=p;
                    break;
                }
            }
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
};