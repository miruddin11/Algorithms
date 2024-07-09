class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long mn=*min_element(enemyEnergies.begin(),enemyEnergies.end());
        if(mn>currentEnergy){
            return 0;
        }
        long long sum=0;
        for(int i=0;i<enemyEnergies.size();i++){
            sum+=(long long) enemyEnergies[i];
        }
        sum+=currentEnergy;
        return sum/mn -1;
    }
};