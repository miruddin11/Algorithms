class Solution {
public:
    int findComplement(int num) {
        string bin="";
        while(num>0){
            int v=num&1;
            bin=bin+to_string(v);
            num>>=1;
        }
        long long ans=0;
        long long x=1;
        for(int i=0;i<bin.size();i++){
            if(bin[i]=='0'){
                ans+=x;
            }
            x=x*2;
        }
        return ans;
    }
};