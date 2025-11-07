class Solution {
public:
    bool check(long long mid,vector<long long>& difference,int r,int k,int n){
        vector<long long> temp=difference;
        long long prefSum=0;
        for(int i=0;i<n;i++){
            prefSum+=temp[i];
            if(prefSum<mid) {
                long long required=mid-prefSum;
                if(required>k){
                    return false;
                }
                k-=required;
                prefSum+=required;
                if(i+2*r+1<n){
                    temp[i+2*r+1]-=required;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long> difference(n,0);
        for(int i=0;i<n;i++) {
            difference[max(0,i-r)]+=stations[i];
            if(i+r+1<n){
                difference[i+r+1]-=stations[i];
            }
        }
        long long low=*min_element(stations.begin(),stations.end());
        long long high=accumulate(stations.begin(),stations.end(),0LL)+k;
        long long maxP=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid,difference,r,k,n)){
                maxP=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return maxP;
    }
};