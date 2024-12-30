class Solution {
public:
    const int mod=1e9+7;
    int Z,O;
    int L,H;
    vector<int> dp;
    int solve(int l)
    {
        if(l>H) return 0;
        if(dp[l]!=-1){
            return dp[l];
        }
        bool addOne=false;
        if(l>=L&&l<=H){
            addOne=true;
        }
        int appendOne=solve(l+O);
        int appendZero=solve(l+Z);

        return dp[l]=(appendOne+appendZero+addOne)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        Z=zero;
        O=one;
        L=low,H=high;
        dp.resize(high+1,-1);
        return solve(0);
    }
};