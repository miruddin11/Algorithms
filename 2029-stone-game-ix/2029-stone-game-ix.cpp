class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for(int stone : stones) {
            cnt[stone % 3]++;
        }
        if(cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};