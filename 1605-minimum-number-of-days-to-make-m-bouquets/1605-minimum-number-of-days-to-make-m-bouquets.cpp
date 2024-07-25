auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    bool solve(vector<int> &a,int m,int k,int mid)
    {
        int b=0;
        int j=0;
        int cnt=0;
        int n=a.size();
        while(j<n)
        {
            if(a[j]<=mid){
                cnt++;
                if(cnt==k){
                    b++;
                    cnt=0;
                }
            }
            else cnt=0;
            if(b>=m) return true;
            j++;
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long res=(long long)m*k;
        if(res>n){
            return -1;
        }
        int low=1,high=1e9;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(bloomDay,m,k,mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};