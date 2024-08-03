class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &x:target){
            mp[x]+=1;
        }
        for(auto &x:arr){
            if(mp.find(x)!=mp.end()){
                mp[x]-=1;
                if(mp[x]==0){
                    mp.erase(x);
                }
            }
            else{
                return false;
            }
        }
        return mp.size()==0;
    }
};