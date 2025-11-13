class Solution {
public:
    int maxOperations(string s) {
        int oneCount=0;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1'){
                oneCount+=1;
            }
            else{
                while(s[i]!='1'&&i<n){
                    i++;
                }
                i--;
                ans+=oneCount;
            }
        }
        return ans;
    }
};