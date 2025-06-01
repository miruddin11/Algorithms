#define ll long long
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto com2=[](int n){
            return 1LL*n*(n-1)/2;
        };
        if(n>3*limit){
            return 0;
        }
        ll ans=com2(n+2);
        if(n>limit){
            ans-=3*com2(n-limit+1);
        }
        if(n-2>=2*limit){
            ans+=3*com2(n-2*limit);
        }
        return ans;
    }
};