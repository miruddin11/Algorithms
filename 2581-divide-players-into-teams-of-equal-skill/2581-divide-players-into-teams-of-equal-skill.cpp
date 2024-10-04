class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int i=0,j=n-1;
        int s=skill[i]+skill[j];
        long long chem=0;
        while(i<j)
        {
            if(s!=skill[i]+skill[j]){
                return -1;
            }
            chem+= (long long) skill[i]* (long long) skill[j];
            i++;
            j--;
        }
        return chem;
    }
};