class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int mxLen=0;
        for(auto &num:nums)
        {
            int len=0;
            long long curr=num;
            while(st.count(curr)>0)
            {
                len+=1;
                if(curr*curr>1e5) break;
                curr*=curr;
            }
            mxLen=max(mxLen,len);
        }
        return mxLen<2?-1:mxLen;
    }
};