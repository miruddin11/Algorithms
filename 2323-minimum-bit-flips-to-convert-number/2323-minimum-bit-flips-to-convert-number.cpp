class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(start&&goal)
        {
            int b1=start&1;
            int b2=goal&1;
            if(b1!=b2){
                cnt+=1;
            }
            start>>=1;
            goal>>=1;
        }
        while(start){
            if(start&1) cnt+=1;
            start>>=1;
        }
        while(goal){
            if(goal&1) cnt+=1;
            goal>>=1;
        }
        return cnt;
    }
};