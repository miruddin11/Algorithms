class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    vector<ll> fact,invFact;
    map<tuple<ll,int,int,int>,ll> dp;
    int M,N,K;
    ll findPower(ll a,ll b){
        if(b==0) return 1;
        ll half=findPower(a,b/2);
        ll result=(half*half)%mod;
        if(b%2==1){
            result=(result*a)%mod;
        }
        return result;
    }
    ll modularnCr(int n,int r){
        // n!/((n-r)!*r!) %mod
        ll ans=((fact[n]*invFact[r])%mod*invFact[n-r])%mod;
        return ans;
    }
    ll solve(ll binarySum,int m,int k,int i,vector<int> &nums){
        auto key=make_tuple(binarySum,m,k,i);
        if(dp.count(key)){
            return dp[key];
        }
        if(m==0&&__builtin_popcountll(binarySum)==k){
            return 1;
        }
        if(m==0||i>=N){
            return 0;
        }
        ll totalSum=0;
        // skip the ith index
        totalSum=(totalSum+ solve( (binarySum>>1) ,m, k-(binarySum&1) ,i+1,nums) )%mod;
        //Take index i for freq no. of times
        for(int freq=1;freq<=m;freq++){
            ll newBinarySum=binarySum+freq;
            ll prod=solve((newBinarySum>>1) ,m-freq, k-(newBinarySum&1) ,i+1,nums) %mod;
            prod=(findPower(nums[i],freq)%mod * prod%mod)%mod;
            prod = (prod*modularnCr(m,freq)%mod)%mod;
            totalSum= (totalSum+prod)%mod;
        }
        return dp[key]=totalSum;
    }
    int magicalSum(int m, int k, vector<int>& nums) {
        int n=nums.size();
        M=m;
        N=n;
        K=k;
        fact.resize(M+1,1);
        invFact.resize(M+1,1);
        fact[0]=1,fact[1]=1;
        for(int i=2;i<=M;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
        //using Fermat's Little theorem => (b!)^-1 % mod = b^(mod-2)% mod
        for(int i=0;i<=M;i++){
            invFact[i]=findPower(fact[i],mod-2);
        }
        return (int) (solve(0,m,k,0,nums)%mod);
    }
};