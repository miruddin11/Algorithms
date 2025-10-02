class Solution {
public:
    int sz;
    vector<vector<int>> ans;
    void solve(int sum,int start,vector<int> &temp)
    {
        if(temp.size()==sz){
            if(sum==0){
                ans.push_back(temp);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            if(sum>=i){
                temp.push_back(i);
                solve(sum-i,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        sz=k;
        ans.clear();
        vector<int> temp;
        solve(n,1,temp);
        return ans;
    }
};