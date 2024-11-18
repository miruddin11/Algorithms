class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        if(k==0){
            return ans;
        }
        int i=-1,j=-1;
        if(k<0){
            i=n-abs(k);
            j=n-1;
        }
        else{
            i=1;
            j=k;
        }
        int sum=0;
        for(int p=i;p<=j;p++){
            sum+=code[p];
        }
        for(int l=0;l<n;l++)
        {
            ans[l]=sum;
            sum-=code[i%n];
            i++;
            sum+=code[(j+1)%n];
            j++;
        }
        return ans;
    }
};