class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int> &values)
    {
        if(j-i<2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mnScore=INT_MAX;
        for(int k=i+1;k<j;k++){
            int weight=values[i]*values[k]*values[j]+solve(i,k,values)+solve(k,j,values);
            mnScore=min(mnScore,weight);
        }
        return dp[i][j]=mnScore;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,n-1,values);
    }
};