class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(auto &num:nums){
            while(ans.size()>0){
                int prev=ans.back();
                int curr=num;
                int gcd=__gcd(prev,curr);
                if(gcd==1){
                    break;
                }
                ans.pop_back();
                int lcm=(prev/gcd)*curr;
                num=lcm;
            }
            ans.push_back(num);
        }
        return ans;
    }
};