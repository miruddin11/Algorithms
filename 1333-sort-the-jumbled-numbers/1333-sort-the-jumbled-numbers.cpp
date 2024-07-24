class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector< pair<int,int> > v; 
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            string s=to_string(x);
            int val=0;
            for(int i=0;i<s.size();i++)
            {
                val=val*10+mapping[s[i]-'0'];
            }
            v.push_back({val,i});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto &i:v){
            ans.push_back(nums[i.second]);
        }
        return ans;
    }
};