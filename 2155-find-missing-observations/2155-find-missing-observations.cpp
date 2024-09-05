class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int totalSum=mean*(m+n);
        int sum=0;
        for(auto &x:rolls) sum+=x;
        int missingSum=totalSum-sum;
        if(missingSum>6*n || missingSum<n){
            return {};
        }
        vector<int> ans;
        while(n)
        {
            int dice=min(6,missingSum-n+1);
            ans.push_back(dice);
            missingSum-=dice;
            n--;
        }
        return ans;
    }
};