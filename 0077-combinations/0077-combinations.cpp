class Solution {
public:
    int limit,sz;
    vector<vector<int>> ans;
    void solve(int start,vector<int> &temp){
        if(temp.size()==sz){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=limit;i++){
            temp.push_back(i);
            solve(i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        limit=n;
        sz=k;
        ans.clear();
        vector<int> temp;
        solve(1,temp);
        return ans;
    }
};