class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &x:arr)
        {
            int rem=(x%k+k)%k;
            mp[rem]+=1;
        }
        if(mp[0]%2!=0){
            return false;
        }
        for(int rem=1;rem<=k/2;rem++){
            int req=k-rem;
            if(mp[rem]!=mp[req]){
                return false;
            }
        }
        return true;
    }
};