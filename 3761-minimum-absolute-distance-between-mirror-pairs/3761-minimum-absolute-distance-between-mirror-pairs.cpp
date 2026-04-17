class Solution {
public:
    int numReverse(int x) {
        int rev = 0;
        while(x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int minDist = INT_MAX;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                minDist = min(minDist , i - mp[nums[i]]);
            }
            mp[numReverse(nums[i])] = i;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};