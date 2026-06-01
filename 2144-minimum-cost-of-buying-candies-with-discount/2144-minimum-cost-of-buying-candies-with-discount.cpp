class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(rbegin(cost), rend(cost));
        int n = cost.size();
        int minCost = 0;
        for(int i = 0; i < n; i += 3) {
            minCost += cost[i];
            if(i + 1 < n) {
                minCost += cost[i + 1];
            }
        }
        return minCost;
    }
};