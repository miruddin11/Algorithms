class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minTime = INT_MAX;
        for(int i = 0; i < n; i++) {
            int time = landStartTime[i] + landDuration[i];
            for(int j = 0; j < m; j++) {
                minTime = min(max(waterStartTime[j], time) + waterDuration[j], minTime);
            }
        }
        for(int i = 0; i < m; i++) {
            int time = waterStartTime[i] + waterDuration[i];
            for(int j = 0; j < n; j++) {
                minTime = min(max(landStartTime[j], time) + landDuration[j], minTime);
            }
        }
        return minTime;
    }
};