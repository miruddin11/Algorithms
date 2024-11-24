class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int cntNeg=0;
        int minNo=INT_MAX;
        long long sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<0){
                    cntNeg+=1;
                }
                minNo=min(minNo,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(cntNeg%2==0){
            return sum;
        }

        return sum-(long long)2*minNo;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();