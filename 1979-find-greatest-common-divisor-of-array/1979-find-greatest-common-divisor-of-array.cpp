class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX, large = INT_MIN;
        for(int &num : nums) {
            small = min(small, num);
            large = max(large, num);
        }
        return gcd(small, large);
    }
};