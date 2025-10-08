class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        auto lowerBound = [&](long long minPotion) {
            long long low = 0, high = m - 1;
            long long ans = -1;
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                if (potions[mid] >= minPotion) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        };
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            long long minPotion = ((success + spells[i] - 1) / spells[i]);
            int idx = lowerBound(minPotion);
            if (idx == -1) {
                continue;
            }
            ans[i] = m - idx;
        }
        return ans;
    }
};