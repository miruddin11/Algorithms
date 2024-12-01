class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(auto &x:arr)
        {
            if((x%2==0&&st.count(x/2))||st.count(2*x)) return true;

            st.insert(x);
        }
        return false;
    }
};