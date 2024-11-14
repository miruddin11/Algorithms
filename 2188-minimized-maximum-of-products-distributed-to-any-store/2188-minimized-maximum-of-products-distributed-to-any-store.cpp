class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());
        auto check=[&](int x,int shops){
            for(auto &p:quantities)
            {
                shops-=(p+x-1)/x;
                if(shops<0){
                    return false;
                }
            }
            return true;
        };
        int ans=0;
        while(l<=r)
        {
            int mid=l+ (r-l)/2;
            if(check(mid,n)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};