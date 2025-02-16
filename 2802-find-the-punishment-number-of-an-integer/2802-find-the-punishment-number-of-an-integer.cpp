class Solution {
public:
    bool check(string s,int num,int i,int currSum)
    {
        if(i==s.size()){
            return currSum==num;
        }
        if(currSum>num){
            return false;
        }
        bool flag=false;
        for(int j=i;j<s.size();j++)
        {
            string t=s.substr(i,j-i+1);
            int val=stoi(t);
            flag=flag || check(s,num,j+1,currSum+val);

            if(flag==true){
                return true;
            }
        }
        return flag;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int num=1;num<=n;num++)
        {
            int sq=num*num;
            string s=to_string(sq);
            if(check(s,num,0,0)){
                sum+=sq;
            }
        }
        return sum;
    }
};