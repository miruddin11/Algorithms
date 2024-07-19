class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int rMinMax=INT_MIN;
        for(int row=0;row<m;row++)
        {
            int rMin=INT_MAX;
            for(int col=0;col<n;col++)
            {
                rMin=min(rMin,matrix[row][col]);
            }
            rMinMax=max(rMinMax,rMin);
        }
        int cMaxMin=INT_MAX;
        for(int col=0;col<n;col++)
        {
            int cMax=INT_MIN;
            for(int row=0;row<m;row++)
            {
                cMax=max(cMax,matrix[row][col]);
            }
            cMaxMin=min(cMaxMin,cMax);
        }
        if(rMinMax==cMaxMin){
            return {cMaxMin};
        }
        return {};
    }
};