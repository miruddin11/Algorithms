class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto &g:gifts){
            pq.push(g);
        }
        while(k--)
        {
            int x=pq.top();
            pq.pop();
            x=sqrt(x);
            pq.push(x);
        }
        long long ans=0;
        while(!pq.empty())
        {
            ans=ans+pq.top();
            pq.pop();
        }
        return ans;
    }
};