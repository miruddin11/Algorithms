class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int a = INT_MAX, b = INT_MIN;
        for(int &num : nums) {
            a = min(a, num);
            b = max(b, num);
        }
        vector<int> ans;
        while(a <= b) {
            if(!st.count(a)) {
                ans.push_back(a);
            }
            a++;
        }
        return ans;
    }
};