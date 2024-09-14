class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(i==0){
                ans.push_back(arr[i]);
                continue;
            }
            auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
            if(it==ans.end()){
                ans.push_back(arr[i]);
            }
            else{
                *it=arr[i];
            }
        }
        return ans.size();
    }
};