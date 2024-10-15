class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
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