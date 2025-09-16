class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> ans;
        for(int i=0;i<nums.size()&&ans.size()<k;i++){
            if(!ans.empty()&&nums[i]==ans.back()){
                continue;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};