class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int cnt = 0;
        for(int x = 0; x <= 200; x++) {
            for(int y = 0; y <= 200; y++) {
                for(auto &c : circles) {
                    int a = c[0], b = c[1] , r = c[2];
                    int sqDis = (x - a) * (x - a) + (y - b) * (y - b);
                    if(sqDis <= r * r) {
                        cnt += 1;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};