class Solution {
public:
    bool isEven(int x)
    {
        int d=0;
        while(x>0){
            x=x/10;
            d++;
        }
        return d%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(auto &x:nums){
            if(isEven(x)){
                cnt++;
            }
        }
        return cnt;
    }
};