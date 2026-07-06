class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto comp = [&](auto &a, auto &b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };
        sort(begin(intervals), end(intervals), comp);
        int count = 0;
        vector<int> prev = intervals[0];
        for(int i = 1; i < n; i++) {
            if(prev[0] == intervals[i][0] || prev[1] >= intervals[i][1]) {
                count += 1;
            } else{
                prev = intervals[i];
            }
        }
        return n - count;
    }
};