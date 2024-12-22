class Solution {
public:
    typedef pair<int,int> P;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m=queries.size();
        unordered_map<int,vector<pair<int,int>>> groups;
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l>r) swap(l,r);
            if(l==r||heights[r]>heights[l])
            {
                ans[i]=r;
            }
            else
            {
                int h=max(heights[l],heights[r]);
                groups[r].push_back({h,i});
            }
        }
        priority_queue<P,vector<P>,greater<P>> minHeap;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            for(auto &q:groups[i])
            {
                minHeap.push(q);
            }
            while(!minHeap.empty()&&heights[i]>minHeap.top().first)
            {
                int idx=minHeap.top().second;
                minHeap.pop();
                ans[idx]=i;
            }
        }
        return ans;
    }
};