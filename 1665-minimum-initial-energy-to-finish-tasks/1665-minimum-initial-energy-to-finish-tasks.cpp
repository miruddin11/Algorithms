class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto comp = [&](vector<int> &a, vector<int> &b) {
            int d1 = a[1] - a[0], d2 = b[1] - b[0];
            return d1 > d2;
        };
        sort(tasks.begin(), tasks.end(), comp);
        int totalInitialEnergy = 0, currEnergy = 0;
        for(auto &task : tasks) {
            int minimum = task[1], actual = task[0];
            if(currEnergy < minimum) {
                int deficit = minimum - currEnergy;
                totalInitialEnergy += deficit;
                currEnergy += deficit;
            }
            currEnergy -= actual;
        }
        return totalInitialEnergy;
    }
};