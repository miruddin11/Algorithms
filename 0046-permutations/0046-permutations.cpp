class Solution {
public:
   vector<vector<int>> ans;
   int n;
   void solve(int idx,vector<int> &arr)
   {
        if(idx==n){
           ans.push_back(arr);
           return;
        }
        for(int i=idx;i<n;i++){
            swap(arr[i],arr[idx]);
            solve(idx+1,arr);
            swap(arr[i],arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        solve(0,nums);
        return ans;
    }
};