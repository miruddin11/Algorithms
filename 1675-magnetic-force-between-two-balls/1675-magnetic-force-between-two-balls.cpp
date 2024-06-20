auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    bool solve(vector<int> &position,int m ,int mid)
    {
        int ball=1;
        int prev=position[0];
        for(int i=1;i<position.size();i++)
        {
            int curr=position[i];
            if(curr>=prev+mid)
            {
                ball++;
                prev=curr;
            }
            if(ball==m){
                return true;
            }
        }
        return (ball==m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position),end(position));
        int n=position.size();
        int low=1,high=position[n-1]-position[0];
        int ans=1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(solve(position,m,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};