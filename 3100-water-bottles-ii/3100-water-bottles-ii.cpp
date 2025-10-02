class Solution {
public:
    int maxBottlesDrunk(int tot, int exchange) {
        int full=tot;
        int empty=0;
        int drink=0;
        drink+=full;
        empty+=full;
        while(empty>=exchange)
        {
            drink+=1;
            empty=empty-exchange+1;
            exchange+=1;
        }
        return drink;
    }
};