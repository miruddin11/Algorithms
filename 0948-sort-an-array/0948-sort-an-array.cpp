class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x:nums){
            mp[x]+=1;
        }
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int j=0;
        for(int i=mn;i<=mx;i++){
            int f=mp[i];
            while(f--){
                nums[j]=i;
                j++;
            }
        }
        return nums;
    }
};