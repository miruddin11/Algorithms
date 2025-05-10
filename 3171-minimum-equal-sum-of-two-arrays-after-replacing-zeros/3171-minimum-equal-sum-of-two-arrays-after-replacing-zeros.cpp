class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=0,s2=0,z1=0,z2=0;
        for(int x:nums1)
        {
            s1+=x;
            if(x==0){
                s1++;
                z1++;
            }
        }
        for(int y:nums2)
        {
            s2+=y;
            if(y==0)
            {
                s2++;
                z2++;
            }
        }
        if(s1==s2){
            return s1;
        }
        else if(s1<s2){
            return z1>0 ? s2:-1;
        }
        else{
            return z2>0 ? s1:-1;
        }
    }
};