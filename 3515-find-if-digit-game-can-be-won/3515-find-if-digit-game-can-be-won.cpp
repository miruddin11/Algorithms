class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sSum=0;
        int dSum=0;
        int sum=0;
        for(auto &x:nums)
        {
            int cnt=0;
            if(x<=9){
                sSum+=x;
            }
            else if(x<=99){
                dSum+=x;
            }
            else{
                sum+=x;
            }
        }
        if(dSum>sum+sSum||sSum>sum+dSum) return true;
        return false;
    }
};