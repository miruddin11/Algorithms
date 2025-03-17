class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &num:nums){
            mp[num]+=1;
        }
        int count=0;
        for(auto &it:mp)
        {
            if(it.second%2!=0){
                return false;
            }
            count+=(it.second/2);
        }
        return count<=(nums.size()/2);
    }
};