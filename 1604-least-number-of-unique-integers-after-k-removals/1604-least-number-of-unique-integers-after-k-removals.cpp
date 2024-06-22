static int speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	return 0;
}();
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &x:arr) mp[x]++;
        vector<int> f;
        for(auto &i:mp) f.push_back(i.second);
        sort(f.begin(),f.end());
        int ans=0;
        for(int i=0;i<f.size();i++)
        {
            if(f[i]<=k){
                k-=f[i];
                ans+=1;
            }
        }
        return f.size()-ans;
    }
};