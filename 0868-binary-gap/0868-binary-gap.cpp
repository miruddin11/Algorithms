class Solution {
public:
    int binaryGap(int n) {
        string bin = "";
        while(n > 0) {
            bin += to_string(n % 2);
            n /= 2;
        }
        reverse(begin(bin) , end(bin));
        int maxDis = 0;
        int prevIdx = -1;
        for(int i = 0; i < bin.size(); i++) {
            if(bin[i] == '0') {
                continue;
            }
            if(prevIdx == -1) {
                prevIdx = i;
            } else {
                int dis = i - prevIdx;
                maxDis = max(dis , maxDis);
                prevIdx = i;
            }
        }
        return maxDis;
    }
};