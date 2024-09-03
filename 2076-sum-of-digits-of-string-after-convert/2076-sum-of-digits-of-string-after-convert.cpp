class Solution {
public:
    int getLucky(string s, int k) {
        string t;
        for(int i=0;i<s.size();i++)
        {
            int x=(s[i]-'a')+1;
            t+=to_string(x);
        }
        string x=t;
        int sum=0;
        while(k>0)
        {
            sum=0;
            for(int i=0;i<x.size();i++)
            {
                sum+=(x[i]-'0');
            }
            if(k!=1){
                x=to_string(sum);
            }
            k--;
        }
        return sum;
    }
};