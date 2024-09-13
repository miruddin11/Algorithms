class Solution {
public:
    vector<vector<int>> dp;
    int solve(int e,int f)
    {
        if(f==1||f==0) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int ans=INT_MAX;
        int low=1,high=f;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int a=solve(e-1,mid-1);
            int b=solve(e,f-mid);
            int x=max(a,b)+1;
            ans=min(ans,x);
            if(a>b) high=mid-1;
            else low=mid+1;
        }
        return dp[e][f]=ans;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,-1));
        return solve(k,n);
    }
};