class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int minCnt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int left=0,right=m-1;
            while(left<right){
                if(grid[i][left]!=grid[i][right]){
                    cnt+=1;
                }
                left++;
                right--;
            }
        }
        minCnt=min(cnt,minCnt);
        cnt=0;
        for(int j=0;j<m;j++)
        {
            int left=0,right=n-1;
            while(left<right)
            {
                if(grid[left][j]!=grid[right][j]){
                    cnt++;
                }
                left++;
                right--;
            }
        }
        minCnt=min(cnt,minCnt);
        return minCnt;
    }
};