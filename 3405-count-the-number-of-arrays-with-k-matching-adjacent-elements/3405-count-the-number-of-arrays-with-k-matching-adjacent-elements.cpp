const int M=1e9+7;
class Solution {
public:
    typedef long long ll;
    vector<ll> fact,invFact;
    ll findPower(ll a,ll b){
        ll result=1LL;
        while(b>0){
            if(b&1){
                result=(result*a)%M;
            }
            a=(a*a)%M;
            b>>=1;
        }
        return result;
    }
    ll modularnCr(int n,int r){
        // n!/((n-r)!*r!) %M
        ll ans=fact[n]*invFact[n-r]%M*invFact[r]%M;
        return ans;
    }
    int countGoodArrays(int n, int m, int k) {
        fact.resize(n+1);
        invFact.resize(n+1);
        fact[0]=1,fact[1]=1;
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%M;
        }
        //using Fermat's Little theorem => (b!)^-1 % M = b^(M-2)% M
        for(int i=0;i<=n;i++){
            invFact[i]=findPower(fact[i],M-2);
        }
        //nCk-1 * m* (m-1)^n-k-1
        ll ans=modularnCr(n-1,k);
        ans=(ans*m)%M;
        ans=(ans*findPower(m-1,n-k-1))%M;
        return ans;
    }
};