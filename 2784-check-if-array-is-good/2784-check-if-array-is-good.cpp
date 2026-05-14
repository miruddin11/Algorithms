class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(n != maxi + 1) {
            return false;
        }
        vector<int> mp(maxi + 1, 0);
        for(auto &x: nums) {
            mp[x] += 1;
        }
        for(int i = 1; i < maxi; i++) {
            if(mp[i] != 1) {
                return false;
            }
        }
        return mp[maxi] == 2;
    }
};