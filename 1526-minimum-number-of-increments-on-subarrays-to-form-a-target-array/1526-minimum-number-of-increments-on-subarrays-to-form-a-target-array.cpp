class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int prev=0,curr=0;
        int n=target.size();
        for(int i=0;i<n;i++)
        {
            curr=target[i];
            if(abs(prev)<abs(curr)){
                ans+=abs(curr-prev);
            }
            prev=curr;
        }
        return ans;
    }
};