class Solution {
public:
    typedef pair<int,int> P;
    long long findScore(vector<int>& nums) {
        long long score=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        int n=nums.size();
        vector<bool> vis(n,false);
        int cnt=0;
        int index=0;
        for(auto &num:nums){
            pq.push({num,index});
            index+=1;
        }
        while(cnt<n&&!pq.empty())
        {
            int smallest=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(vis[idx]==false){
                score+=smallest;
                cnt+=1;
                vis[idx]=true;
                if(idx-1>=0&&vis[idx-1]==false){
                    vis[idx-1]=true;
                    cnt+=1;
                }
                if(idx+1<n&&vis[idx+1]==false){
                    vis[idx+1]=true;
                    cnt+=1;
                }
            }
        }
        return score;
    }
};