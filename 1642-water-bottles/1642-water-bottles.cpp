class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles,temp=0;
        while(numExchange<=numBottles)
        {
            temp=numBottles%numExchange;
            numBottles=numBottles-temp;
            ans+=numBottles/numExchange;
            numBottles=(numBottles/numExchange)+temp;
        }
        return ans;
    }
};