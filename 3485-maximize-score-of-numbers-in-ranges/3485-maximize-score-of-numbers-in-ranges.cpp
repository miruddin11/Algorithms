class Solution {
public:
    typedef long long ll;
    int maxPossibleScore(vector<int>& start, int d) {
        int n=start.size();
        sort(start.begin(),start.end());
        auto check=[&](ll mid){
            ll prev=start[0];
            for(int i=1;i<n;i++)
            {
                ll next=max(prev+mid,(ll)start[i]);
                if(next>start[i]+d){
                    return false;
                }
                prev=next;
            }
            return true;
        };
        ll low=0,high=start[n-1]-start[0]+d;
        ll ans=0;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(check(mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};