class Solution {
public:
    typedef long long ll;
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(),m=points[0].size();
        vector<ll> prev(points[0].begin(),points[0].end());
        for(int i=1;i<n;i++)
        {
            vector<ll> curr(points[i].begin(),points[i].end());
            vector<ll> left(m),right(m);
            left[0]=prev[0];
            for(int j=1;j<m;j++)
            {
                left[j]=max(left[j-1]-1ll,prev[j]);
            }
            right[m-1]=prev[m-1];
            for(int j=m-2;j>=0;j--)
            {
                right[j]=max(right[j+1]-1ll,prev[j]);
            }
            for(int j=0;j<m;j++)
            {
                curr[j]=curr[j]+max(left[j],right[j]);
            }
            prev=curr;
        }
        ll ans=LLONG_MIN;
        for(auto &x:prev){
            ans=max(ans,x);
        }
        return ans;
    }
};