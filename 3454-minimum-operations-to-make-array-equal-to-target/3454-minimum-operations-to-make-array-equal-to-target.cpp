class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=target[i]-nums[i];
        }
        int prev=0,curr=0;
        long long operation=0;
        for(int i=0;i<n;i++)
        {
            curr=diff[i];
            if((curr<0&&prev>0)||(curr>0&&prev<0)){
                operation+=(long long)abs(curr);
            }
            else if(abs(prev)<abs(curr)){
                operation+=(long long) abs(curr-prev);
            }
            prev=curr;
        }
        return operation;
    }
};