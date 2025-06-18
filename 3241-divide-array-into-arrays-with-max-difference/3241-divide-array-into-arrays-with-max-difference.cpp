class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        vector<vector<int>> ans;
        while(i<n)
        {
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            if((b-a)<=k&&(c-b)<=k&&(c-a)<=k)
            {
                vector<int> v(3);
                v[0]=a,v[1]=b,v[2]=c;
                ans.push_back(v);
            }
            else{
                vector<vector<int>> temp;
                return temp;
            }
            i+=3;
        }
        return ans;
    }
};