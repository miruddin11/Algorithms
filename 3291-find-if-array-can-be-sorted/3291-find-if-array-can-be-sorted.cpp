class Solution {
public:
    bool canSortArray(vector<int>& a) {
        int n=a.size();
        for(int j=1;j<=100;j++)
        {
            for(int i=0;i<n-1;i++){
                if(a[i]>a[i+1]){
                    int x=__builtin_popcount(a[i]);
                    int y=__builtin_popcount(a[i+1]);
                    if(x!=y) return false;
                    else swap(a[i],a[i+1]);
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1]) return false;
        }
        
        return true;
    }
};