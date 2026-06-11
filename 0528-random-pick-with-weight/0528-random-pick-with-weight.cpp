class Solution {
public:
    vector<int> prefixSums;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int x : w) {
            sum += x;
            prefixSums.push_back(sum);
        }
    }

    int pickIndex() {
        int totSum = prefixSums.back();
        int target = rand() % totSum;
        auto it = upper_bound(begin(prefixSums), end(prefixSums), target);
        return it - prefixSums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */