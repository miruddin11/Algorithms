class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int l=0,r=n;
        while(l<n&&r<2*n){
            ans.push_back(nums[l]);
            ans.push_back(nums[r]);
            l++;
            r++;
        }
        return ans;
    }
};