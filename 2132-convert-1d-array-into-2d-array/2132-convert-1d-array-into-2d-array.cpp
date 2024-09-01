class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len=original.size();
        if(len>m*n||len<m*n){
            return {};
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<len;i++)
        {
            int row=i/n,col=i%n;
            ans[row][col]=original[i];
        }
        return ans;
    }
};