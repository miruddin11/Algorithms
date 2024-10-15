class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        long long black_cnt=0;
        for(auto &x:s){
            if(x=='1'){
                black_cnt+=1;
            }
            else{
                ans+=black_cnt;
            }
        }
        return ans;
    }
};