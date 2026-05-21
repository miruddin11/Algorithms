class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_set<int> st;
        for(auto &x : arr1) {
            int a = x;
            while(a > 0) {
                st.insert(a);
                a /= 10;
            }
        }
        for(auto &x : arr2) {
            int a = x;
            while(a > 0) {
                if(st.find(a) != st.end()) {
                    ans = max(ans, (int) log10(a) + 1);
                    break;
                }
                a /= 10;
            }
        }
        return ans;
    }
};