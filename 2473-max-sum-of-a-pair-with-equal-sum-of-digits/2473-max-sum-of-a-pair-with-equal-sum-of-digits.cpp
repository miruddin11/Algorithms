class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> mp;
        for(auto &num:nums)
        {
            int x=num,sum=0;
            while(x!=0){
                sum+=(x%10);
                x/=10;
            }
            mp[sum].push(num);
        }
        int maxSum=-1;
        for(auto &it:mp)
        {
            priority_queue<int> pq=it.second;
            if(pq.size()>=2){
                int sum=pq.top();
                pq.pop();
                sum+=pq.top();
                pq.pop();
                maxSum=max(sum,maxSum);
            }
        }
        return maxSum;
    }
};