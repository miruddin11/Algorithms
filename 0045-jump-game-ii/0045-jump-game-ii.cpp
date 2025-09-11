class Solution {
public:
    int jump(vector<int>& arr) {
        int jumps=0;
        int l=0,r=0,n=arr.size();
        while(r<n-1)
        {
            int farthest=0;
            for(int idx=l;idx<=r;idx++)
            {
                farthest=max(idx+arr[idx],farthest);
            }
            if(farthest==r){
                return -1;
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};