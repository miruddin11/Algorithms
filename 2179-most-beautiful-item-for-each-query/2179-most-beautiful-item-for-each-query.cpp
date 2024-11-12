class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        sort(items.begin(),items.end());
        int mxBeauty=items[0][1];
        for(int i=1;i<n;i++)
        {
            mxBeauty=max(mxBeauty,items[i][1]);
            items[i][1]=mxBeauty;
        }
        vector<int> ans;
        auto findMax=[&](int q){
            int l=0,r=n-1;
            int ans=-1;
            while(l<=r)
            {
                int mid=l+ (r-l)/2;
                if(items[mid][0]<=q){
                    ans=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            return ans;
        };
        for(auto &q:queries)
        {
            int idx=findMax(q);
            if(idx==-1){
                ans.push_back(0);
            }
            else{
                ans.push_back(items[idx][1]);
            }
        }
        return ans;
    }
};