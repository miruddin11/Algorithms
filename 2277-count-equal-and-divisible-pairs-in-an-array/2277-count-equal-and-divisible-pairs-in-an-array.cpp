class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        unordered_map<int, vector<int>> indicesMap;
        for(int i = 0; i < n; i++) {
            indicesMap[nums[i]].push_back(i);
        }
        unordered_set<int> div;
        for(int f = 1; f*f <= k; f++) { 
            if(k%f == 0) {
                div.insert(f);
                div.insert(k/f);
            }
        }
        for(auto& [num, indices] : indicesMap) {
            unordered_map<int, int> factorsMap;
            for(int i : indices) {
                int GCD = gcd(i, k); 
                int j   = k / GCD;
                result += factorsMap[j];
                for(int f : div) {
                    if(i % f == 0) {
                        factorsMap[f]++;
                    }
                }
            }
        }
        return result;
    }
};