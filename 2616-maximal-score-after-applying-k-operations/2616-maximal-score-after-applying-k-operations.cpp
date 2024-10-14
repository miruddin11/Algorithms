class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(auto &x:nums){
            pq.push(x);
        }
        while(k>0)
        {
            long long x=pq.top();
            ans+=x;
            pq.pop();
            int v=(x+3-1)/3;
            pq.push(v);
            k--;
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();