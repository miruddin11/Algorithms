class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int maxConfusion=0;
        //by maximising 'T' count
        int i=0,j=0;
        int Fcount=0;
        while(j<n)
        {
            if(answerKey[j]=='F') Fcount+=1;
            while(Fcount>k)
            {
                if(answerKey[i]=='F') Fcount-=1;
                i++;
            }
            maxConfusion=max(maxConfusion,j-i+1);
            j++;
        }
        //by maximising 'F' count
        int Tcount=0;
        i=0,j=0;
        while(j<n)
        {
            if(answerKey[j]=='T') Tcount+=1;
            while(Tcount>k)
            {
                if(answerKey[i]=='T') Tcount-=1;
                i++;
            }
            maxConfusion=max(maxConfusion,j-i+1);
            j++;
        }
        return maxConfusion;
    }
};