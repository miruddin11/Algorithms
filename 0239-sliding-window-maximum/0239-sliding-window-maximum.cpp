class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int i=0,j=0;
        int n=nums.size();
        vector<int> ans;
        while(j<n)
        {
            pq.push({nums[j],j});
            while(!pq.empty()&&pq.top().second<i){
                    pq.pop();
            }
            if(j-i+1==k){
                if(!pq.empty()){
                    ans.push_back(pq.top().first);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};