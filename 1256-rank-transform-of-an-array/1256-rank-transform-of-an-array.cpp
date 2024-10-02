class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> v;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int r=1;
        vector<int> rank(n,0);
        for(int i=0;i<n;i++)
        {
            if(i>0&&v[i].first==v[i-1].first){
                rank[v[i].second]=rank[v[i-1].second];
            }
            else{
                rank[v[i].second]=r;
                r++;   
            }
        }
        return rank;
    }
};