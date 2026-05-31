class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        long long totalMass = mass;
        for(int &asteroid : asteroids) {
            if(totalMass < asteroid)
                return false;
            totalMass += asteroid;
        }
        return true;
    }
};