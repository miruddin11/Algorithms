class Solution {
public:
    typedef pair<int,int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<P,vector<P>,greater<P>> minPq;
        priority_queue<P,vector<P>> maxPq;
        int i=0,j=0,n=nums.size();
        int mxlen=0;
        while(j<n)
        {
            minPq.push({nums[j],j});
            maxPq.push({nums[j],j});
            while(maxPq.top().first - minPq.top().first >limit)
            {
                i=min(maxPq.top().second,minPq.top().second)+1;
                while(minPq.top().second <i){
                    minPq.pop();
                }
                while(maxPq.top().second <i){
                    maxPq.pop();
                }
            }
            mxlen=max(mxlen,j-i+1);
            j++;
        }
        return mxlen;
    }
};