class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int i=0,j=0,n=nums.size();
        int mxlen=0;
        while(j<n)
        {
            st.insert(nums[j]);
            while(*st.rbegin()-*st.begin() >limit)
            {
                st.erase(st.find(nums[i]));
                i++;
            }
            mxlen=max(mxlen,j-i+1);
            j++;
        }
        return mxlen;
    }
};