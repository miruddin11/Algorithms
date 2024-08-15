#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCnt=0;
        int TenCnt=0;
        if(bills[0]!=5){
            return false;
        }
        fiveCnt+=1;
        for(int i=1;i<bills.size();i++)
        {
            if(bills[i]==5){
                fiveCnt+=1;
            }
            else if(bills[i]==10){
                if(fiveCnt>=1){
                    fiveCnt-=1;
                    TenCnt+=1;
                }
                else{
                    return false;
                }
            }
            else if(bills[i]==20){
                if(TenCnt>=1&&fiveCnt>=1){
                    TenCnt-=1;
                    fiveCnt-=1;
                }
                else if(fiveCnt>=3){
                    fiveCnt-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};