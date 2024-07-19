class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> row;
        for(int i=0;i<m;i++)
        {
            int mn=INT_MAX;
            for(int j=0;j<n;j++){
                mn=min(mn,matrix[i][j]);
            }
            row.push_back(mn);
        }
        vector<int> col;
        for(int j=0;j<n;j++)
        {
            int mx=INT_MIN;
            for(int i=0;i<m;i++){
                mx=max(mx,matrix[i][j]);
            }
            col.push_back(mx);
        }
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==row[i]&&matrix[i][j]==col[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};