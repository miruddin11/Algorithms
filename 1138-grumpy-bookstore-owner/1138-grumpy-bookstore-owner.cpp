class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        int maxUnsatCust=0;
        int i=0,j=0;
        int currUnsatCust=0;
        while(j<n)
        {
            currUnsatCust+=customers[j]*grumpy[j];
            if(j-i+1==minutes){
                maxUnsatCust=max(maxUnsatCust,currUnsatCust);
                currUnsatCust-=customers[i]*grumpy[i];
                i++;
            }
            j++;
        }
        int ans=maxUnsatCust;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }
        return ans;
    }
};