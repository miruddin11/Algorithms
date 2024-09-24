class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto &x:arr1){
            while(x!=0&&st.find(x)==st.end()){
                st.insert(x);
                x/=10;
            }
        }
        int ans=0;
        for(auto &y:arr2){
            while(y!=0&&st.find(y)==st.end()){
                y/=10;
            }
            if(y!=0){
                ans=max(ans,static_cast<int>(log10(y)+1));
            }
        }
        return ans;
    }
};