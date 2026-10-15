class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                int cnt = st.size();
                res += cnt * cnt;
            }
            st.clear();
        }
        return res;
    }
};