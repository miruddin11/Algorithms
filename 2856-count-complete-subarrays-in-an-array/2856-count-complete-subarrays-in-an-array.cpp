class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int distinct_ele=st.size();
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> s;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                if(s.size()==distinct_ele) cnt+=1;
            }
        }
        return cnt;
    }
};