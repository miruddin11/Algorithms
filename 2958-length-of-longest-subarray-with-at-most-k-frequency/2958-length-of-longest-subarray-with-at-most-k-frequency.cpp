class Solution {
public:
    bool check(int x, int n, vector<int> &a, int k)
    {
        int c = 0;
        unordered_map<int, int> mp;
        for(int i = 0;i < n; i++) {
            mp[a[i]]++;
            if(mp[a[i]] == k + 1) {
                c += 1;
            }
            if(x <= i) {
                mp[a[i - x]]--;
                if(k == mp[a[i - x]]) {
                    c -= 1;
                }
            }
            if(c == 0) {
                if(i >= x - 1) {
                    return true;
                }
            }
        }
        return false;
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 1, end = n + 1;
        while(start < end) {
            int mid = (start + end) / 2;
            if(check(mid, n, nums, k)) {
                start = mid + 1;
            } else{
                end = mid;
            }
        }
        return start - 1;
    }
};