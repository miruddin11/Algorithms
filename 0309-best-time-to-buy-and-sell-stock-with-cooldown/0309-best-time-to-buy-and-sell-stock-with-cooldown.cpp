class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int> &prices,int idx,bool buy){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy){
            int take=solve(prices,idx+1,false)-prices[idx];
            int notTake=solve(prices,idx+1,true);
            profit=max({profit,take,notTake});
        }
        else{
            int sell=solve(prices,idx+2,true)+prices[idx];
            int notSell=solve(prices,idx+1,false);
            profit=max({profit,sell,notSell});
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(prices,0,true);
    }
};