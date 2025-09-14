class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasCost=0,totalGasEarned=0,n=gas.size();
        for(int i=0;i<n;i++){
            totalGasCost+=cost[i];
            totalGasEarned+=gas[i];
        }
        if(totalGasCost>totalGasEarned){
            return -1;
        }
        int resultIdx=0;
        int totalCost=0;
        for(int i=0;i<n;i++)
        {
            totalCost=totalCost+gas[i]-cost[i];
            if(totalCost<0){
                totalCost=0;
                resultIdx=i+1;
            }
        }
        return resultIdx;
    }
};