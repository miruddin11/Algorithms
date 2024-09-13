class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]^arr[i];
        }
        int m=queries.size();
        vector<int> ans(m,0);
        for(int k=0;k<m;k++){
            int i=queries[k][0];
            int j=queries[k][1];
            if(i>0) ans[k]=pre[i-1]^pre[j];
            else ans[k]=pre[j];
        }
        return ans;
    }
};