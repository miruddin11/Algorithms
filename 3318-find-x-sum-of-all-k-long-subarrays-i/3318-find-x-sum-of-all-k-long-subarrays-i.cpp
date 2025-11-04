class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        for(int i=0;i<n-k+1;i++){
            unordered_map<int,int> mp;
            for(int j=i;j<i+k;j++){
                mp[nums[j]]+=1;
            }
            priority_queue<pair<int,int>> pq;
            for(auto &[ele,freq]:mp){
                pq.push({freq,ele});
            }
            long long sum=0;
            int val=x;
            while(!pq.empty()&&val>0){
                auto P=pq.top();
                pq.pop();
                sum+=(long long)(P.first*P.second);
                val--;
            }
            ans[i]=sum;
        }
        return ans;
    }
};