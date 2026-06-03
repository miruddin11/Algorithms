class Solution {
public:
    int solve(vector<int> &firstTime, vector<int> &firstDuration, vector<int> &lastTime, vector<int> &lastDuration) {
        int minTime = INT_MAX, n = firstTime.size(), m = lastTime.size();
        int time = INT_MAX;
        for(int i = 0; i < n; i++) {
            time = min(time, firstTime[i] + firstDuration[i]);
        }
        for(int i = 0; i < m; i++) {
            minTime = min(minTime, max(time, lastTime[i]) + lastDuration[i]);
        }
        return minTime;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration), solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};