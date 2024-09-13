class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            arr[i]=arr[i-1]^arr[i];
        }
        int m=queries.size();
        vector<int> ans;
        for(auto &q:queries){
            if(q[0]>0) ans.push_back(arr[q[0]-1]^arr[q[1]]);
            else ans.push_back(arr[q[1]]);
        }
        return ans;
    }
};