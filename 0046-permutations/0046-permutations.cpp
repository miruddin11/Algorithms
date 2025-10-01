class Solution {
public:
   vector<vector<int>> ans;
   int n;
   unordered_set<int> st;
   void solve(vector<int> &temp,vector<int> &arr)
   {
        if(temp.size()==n){
           ans.push_back(temp);
           return;
        }
        for(int i=0;i<n;i++){
            if(st.find(arr[i])==st.end()){
                temp.push_back(arr[i]);
                st.insert(arr[i]);
                solve(temp,arr);
                temp.pop_back();
                st.erase(arr[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        solve(temp,nums);
        return ans;
    }
};