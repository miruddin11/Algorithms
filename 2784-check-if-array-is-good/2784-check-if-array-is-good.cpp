class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(n != maxi + 1) {
            return false;
        }
        unordered_map<int, int> mp;
        for(int i = 1; i <= maxi; i++) {
            mp[i] += 1;
        }
        mp[maxi] += 1;
        for(auto &x : nums) {
            if(mp.find(x) != mp.end()) {
                mp[x] -= 1;
                if(mp[x] == 0) {
                    mp.erase(x);
                }
            }
        }
        return mp.size() == 0;
    }
};