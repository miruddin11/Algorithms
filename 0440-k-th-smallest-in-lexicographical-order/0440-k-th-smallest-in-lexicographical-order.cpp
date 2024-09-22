class Solution {
public:
    int fun(long long curr,long long next,int n)
    {
        int Numcnt=0;
        while(curr<=n){
            Numcnt+=next-curr;
            curr*=10;
            next*=10;
            next=min(next,(long long)n+1);
        }
        return Numcnt;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k-=1;
        while(k>0)
        {
            int count=fun(curr,curr+1,n);
            if(count<=k){
                //skip the tree
                curr++;
                k-=count;
            }
            else{
                // same tree deeper
                curr*=10;
                k-=1;
            }
        }
        return curr;
    }
};