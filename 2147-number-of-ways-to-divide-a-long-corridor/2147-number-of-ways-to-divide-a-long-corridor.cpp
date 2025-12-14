class Solution {
public:
    int numberOfWays(string corridor) {
        int chairs=0;
        long long result = 1;
        int n=corridor.size();
        const int mod=1000000007;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                chairs++;
                while(++i<n&&corridor[i]!='S');
                if(i<n&&corridor[i]=='S'){
                    chairs++;
                }
                int divisions=1;
                while(++i<n&&corridor[i]!='S'){
                    divisions++;
                }          
                if (divisions>1&&i<n){
                    result=(result*divisions)%mod;
                }
                i--;
            }
        }
        return (chairs!=0&&chairs%2==0)?(int)result:0;
    }
};