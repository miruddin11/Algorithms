class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P,vector<P>,greater<P>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            int mn=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            nums[idx]=mn*multiplier;
            pq.push({nums[idx],idx});
        }
        return nums;
    }
};