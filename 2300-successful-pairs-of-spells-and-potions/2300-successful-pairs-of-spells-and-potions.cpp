class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int minPotion=((success+spells[i]-1)/spells[i]);
            auto it=lower_bound(potions.begin(),potions.end(),minPotion);
            if(it==potions.end()){
                continue;
            }
            int idx=it-potions.begin();
            ans[i]=m-idx;
        }
        return ans;
    }
};