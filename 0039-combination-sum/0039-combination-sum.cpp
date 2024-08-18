class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,vector<int> &candidates,vector<int> &temp,int target)
    {
        if(idx>=candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        temp.push_back(candidates[idx]);
        solve(idx,candidates,temp,target-candidates[idx]);
        temp.pop_back();
        solve(idx+1,candidates,temp,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0,candidates,temp,target);
        return ans;
    }
};