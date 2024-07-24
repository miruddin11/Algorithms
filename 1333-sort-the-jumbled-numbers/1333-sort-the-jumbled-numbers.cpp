class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector< pair<int,int> > v; 
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            if(x<10){
                v.push_back({mapping[x],i});
                continue;
            }
            int val=0;
            int place=1;
            while(x>0){
                int d=x%10;
                val=val+mapping[d]*place;
                x=x/10;
                place*=10;
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