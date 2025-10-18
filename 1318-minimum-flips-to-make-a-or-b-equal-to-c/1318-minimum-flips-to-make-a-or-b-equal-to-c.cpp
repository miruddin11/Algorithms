class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<=31;i++){
            int aIthBit=(a>>i)&1;
            int bIthBit=(b>>i)&1;
            int cIthBit=(c>>i)&1;
            if((aIthBit|bIthBit)==cIthBit){
                continue;
            }
            else if(cIthBit==1){
                count+=1;
            }
            else{
                count+=aIthBit+bIthBit;
            }
        }
        return count;
    }
};