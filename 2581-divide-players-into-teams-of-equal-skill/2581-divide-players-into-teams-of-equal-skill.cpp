class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<int> count(1001,0);
        int sum=0;
        for(auto &x:skill)
        {
            sum+=x;
            count[x]+=1;
        }
        int n=skill.size();
        int teams=n/2;
        if(sum%teams!=0){
            return -1;
        }
        long long chem=0;
        int target=sum/teams;
        for(int i=0;i<n;i++)
        {
            int currSkill=skill[i];
            int reqSkill=target-currSkill;
            if(count[reqSkill]<=0){
                return -1;
            }
            chem+=(long long) currSkill*(long long) reqSkill;
            count[reqSkill]--;
        }
        return chem/2;
    }
};