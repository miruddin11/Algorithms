class Solution {
public:
    long f(long firstHalf,bool isEven)
    {
        long ans=firstHalf;
        if(!isEven) firstHalf/=10;
        while(firstHalf>0)
        {
            int d=firstHalf%10;
            ans= ans*10+d;
            firstHalf/=10;
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        int len=n.size();
        int firstHalfLen=(len%2==0)?(len/2):(len/2 +1);
        long firstHalf=stol(n.substr(0,firstHalfLen));
        vector<long> temp;
        temp.push_back(f(firstHalf,len%2==0));
        temp.push_back(f(firstHalf+1,len%2==0));
        temp.push_back(f(firstHalf-1,len%2==0));
        temp.push_back((long)pow(10,len-1)-1);
        temp.push_back((long)pow(10,len)+1);

        long d=LONG_MAX;
        long ans=LONG_MAX;
        long num=stol(n);
        for(auto &x:temp)
        {
            if(x==num) continue;
            if(abs(x-num)<d){
                d=abs(x-num);
                ans=x;
            }
            else if(abs(x-num)==d){
                ans=min(x,ans);
            }
        }
        return to_string(ans);
    }
};