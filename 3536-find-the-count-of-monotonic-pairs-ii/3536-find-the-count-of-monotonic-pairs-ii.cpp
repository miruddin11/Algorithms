class Solution {
public:
    int MOD=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        //vector<vector<int>> dp(n,vector<int>(51,0));
        vector<vector<int>> dp(n,vector<int>(1001,0));
        for(int i=0;i<=nums[0];i++) dp[0][i]=1;

        for(int i=1;i<n;i++)
        {
            int k=0;
            int temp=0;
            for(int j=0;j<=nums[i];j++)
            {
                // int arr1=j;
                // int arr2=nums[i]-j;
                // for(int k=arr1;k>=0;k--)
                // {
                //     if(arr2<=nums[i-1]-k){
                //         dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                //     }
                // }
                // k<=j&&nums[i-1]-k>=nums[i]-j
                // k<=min(j,j-(nums[i]-nums[i-1]))
                // for j+1,the k will be
                // k1<=min(j+1,j+1-(nums[i]-nums[i-1]))
                if(k<=min(j,j-(nums[i]-nums[i-1]))){
                    temp=(temp+dp[i-1][k])%MOD;
                    k++;
                }
                dp[i][j]=temp;
            }
        }
        int ans=0;
        for(int i=0;i<1001;i++){
            ans= (ans+dp[n-1][i])%MOD;
        }

        return ans;

    }
};