class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto comp = [&](vector<int> &a, vector<int> &b) {
            int d1 = a[1] - a[0], d2 = b[1] - b[0];
            return d1 > d2;
        };
        sort(tasks.begin(), tasks.end(), comp);
        auto isPossible = [&](int mid) {
            for(auto &task : tasks) {
                if(mid >= task[1]) {
                    mid -= task[0];
                } else {
                    return false;
                }
            }
            return true;
        };
        int low = 0, high = 1e9, ans = 1e9;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};