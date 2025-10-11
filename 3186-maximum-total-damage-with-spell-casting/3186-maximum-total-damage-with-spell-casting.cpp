class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> freqMap;
        for (auto& p : power) {
            freqMap[p]++;
        }
        vector<long long> uniqueDamage;
        for (auto& [d, _] : freqMap) {
            uniqueDamage.push_back(d);
        }
        int len = uniqueDamage.size();
        vector<long long> dp(len, 0);
        dp[0] = freqMap[uniqueDamage[0]] * uniqueDamage[0];
        for (int i = 1; i < len; i++) {
            long long currDamage = uniqueDamage[i];
            long long totCurrDamage = currDamage * freqMap[currDamage];
            dp[i] = dp[i - 1];
            int prevIdx = i - 1;
            while (prevIdx >= 0 && (currDamage - 1 == uniqueDamage[prevIdx] ||
                                    currDamage - 2 == uniqueDamage[prevIdx] ||
                                    currDamage + 1 == uniqueDamage[prevIdx] ||
                                    currDamage + 2 == uniqueDamage[prevIdx])) {
                prevIdx--;
            }
            if (prevIdx >= 0) {
                dp[i] = max(dp[i], dp[prevIdx] + totCurrDamage);
            } else {
                dp[i] = max(dp[i], totCurrDamage);
            }
        }
        return dp[len - 1];
    }
};