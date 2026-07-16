class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            nums[i] = gcd(nums[i], mx);
        }
        sort(begin(nums), end(nums));
        long long ans = 0;
        for(int i = 0; i < n / 2; i++) {
            ans += (long long)gcd(nums[i], nums[n - i - 1]);
        }
        return ans;
    }
};