class Solution {
public:
    string fractionAddition(string expression) {
        int n=0,d=1;
        int i=0;
        int len=expression.size();
        while(i<len)
        {
            int cn=0,cd=0;
            bool isNeg=(expression[i]=='-');
            if(expression[i]=='+'||expression[i]=='-'){
                i++;
            }
            while(i<len&&isdigit(expression[i]))
            {
                int val=expression[i]-'0';
                cn=(cn*10)+val;
                i++;
            }
            if(isNeg) cn*=-1;
            i++;
            while(i<len&&isdigit(expression[i]))
            {
                int val=expression[i]-'0';
                cd=(cd*10)+val;
                i++;
            }
            n= n*cd + cn*d;
            d= d*cd;
        }
        int gcd=abs(__gcd(n,d));
        return to_string(n/gcd)+"/"+to_string(d/gcd);
    }
};