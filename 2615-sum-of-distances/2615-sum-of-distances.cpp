class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> arr(n, 0);
        unordered_map<int, ll> indexSum;   
        unordered_map<int, ll> indexCount; 
        for(int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];
            arr[i] += freq*i - sum;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }
        indexSum.clear();
        indexCount.clear();
        for(int i = n-1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];
            arr[i] += sum - freq*i;
            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }
        return arr;
    }
};