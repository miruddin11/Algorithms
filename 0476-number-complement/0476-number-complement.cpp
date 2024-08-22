class Solution {
public:
    int findComplement(int num) {
        long long ans=0;
        long long x=1;
        while(num>0){
            if((num&1)==0){
                ans+=x;
            }
            num>>=1;
            x=x*2;
        }
        return ans;
    }
};