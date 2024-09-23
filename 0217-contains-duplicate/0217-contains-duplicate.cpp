class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x:nums){
            if(st.find(x)!=st.end()){
                return true;
            }
            st.insert(x);
        }
        return false;
    }
};