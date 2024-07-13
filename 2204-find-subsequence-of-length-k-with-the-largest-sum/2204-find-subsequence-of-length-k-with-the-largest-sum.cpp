class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.rbegin(),v.rend());
        vector<int> ans;
        int i=0;
        while(k--){
            ans.push_back(v[i].second);
            i++;
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            ans[i]=nums[ans[i]];
        }
        return ans;
    }
};