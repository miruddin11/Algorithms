class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int n = cost.size();
        int minCost = 0;
        for(int i = n - 1; i >= 0; i -= 3) {
            minCost += cost[i];
            if(i - 1 >= 0) {
                minCost += cost[i - 1];
            }
        }
        return minCost;
    }
};