class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            arr[i]=arr[i-1]^arr[i];
        }
        int m=queries.size();
        vector<int> ans(m,0);
        for(int k=0;k<m;k++){
            int i=queries[k][0];
            int j=queries[k][1];
            if(i>0) ans[k]=arr[i-1]^arr[j];
            else ans[k]=arr[j];
        }
        return ans;
    }
};