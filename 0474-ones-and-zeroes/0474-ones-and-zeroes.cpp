class Solution {
public:
    int dp[101][101][601];
    int solve(vector<pair<int,int>>& count,int m,int n,int idx){
        if(idx>=count.size()||(m == 0 && n == 0)){
            return 0;
        }
        if(dp[m][n][idx]!=-1){
            return dp[m][n][idx];
        }
        int include=0;
        if(count[idx].first<=m&&count[idx].second<=n){
            include=1+solve(count,m-count[idx].first,n-count[idx].second,idx+1);
        }
        int exclude=solve(count,m,n,idx+1);
        return dp[m][n][idx]=max(include,exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<pair<int,int>> count(len);
        int i=0;
        for(string str:strs) {
            int countOnes=0;
            int countZeros=0;
            for(char ch:str) {
                if(ch=='1'){
                    countOnes++;
                }
                else{
                    countZeros++;
                }
            }
            count[i++]={countZeros,countOnes};
        }        
        memset(dp,-1,sizeof(dp));
        return solve(count,m,n,0);
    }
};