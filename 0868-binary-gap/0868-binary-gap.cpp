class Solution {
public:
    int binaryGap(int n) {
        int maxDis = 0;
        int prevIdx = -1;
        int i = 0;
        while(n) {
            if(n & 1) {
                if(prevIdx == -1) {
                    prevIdx = i;
                } else {
                    int dis = i - prevIdx;
                    maxDis = max(dis , maxDis);
                    prevIdx = i;
                }   
            }
            i++;
            n = n >> 1;
        }
        return maxDis;
    }
};