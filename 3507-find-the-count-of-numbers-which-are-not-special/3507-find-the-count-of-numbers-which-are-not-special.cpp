class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n=1e5;
        vector<bool> is_prime(n+1,true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i<=n;i++)
        {
            if(is_prime[i]){
                for(int j=2*i;j<=n;j+=i){
                    is_prime[j]=false;
                }
            }
        }
        int cnt=0;
        int j=sqrt(l);
        if(j*j<l){
            j++;
        }
        for(;j*j<=r;j++){
            if(is_prime[j]){
                cnt++;
            }
        }
        return r-l+1-cnt;
    }
};