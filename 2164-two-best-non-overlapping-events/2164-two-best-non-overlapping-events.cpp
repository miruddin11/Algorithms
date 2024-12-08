class Solution {
public:
    vector<vector<int>> dp;
    int binarySearch(vector<vector<int>> &events,int endTime,int n)
    {
        int l=0,r=n-1;
        int ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(events[mid][0]>endTime){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>> &events,int i,int count,int n)
    {
        if(count==2||i>=n){
            return 0;
        }
        if(dp[i][count]!=-1){
            return dp[i][count];
        }
        int nextValidEventIdx=binarySearch(events,events[i][1],n);
        int take=events[i][2]+solve(events,nextValidEventIdx,count+1,n);
        int notTake=solve(events,i+1,count,n);
        return dp[i][count]=max(take,notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        dp.resize(n+1,vector<int>(3,-1));
        sort(events.begin(),events.end());
        int count=0;
        return solve(events,0,count,n);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();