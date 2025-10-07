class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int> rainDay;
        set<int> alreadyRained;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            int lake=rains[i];
            if(lake==0){
                alreadyRained.insert(i);
            }
            else{
                ans[i]=-1;
                if(rainDay.count(lake)>0){
                    auto it=alreadyRained.lower_bound(rainDay[lake]);
                    if(it==alreadyRained.end()){
                        return {};
                    }
                    int day=*it;
                    ans[day]=lake;
                    alreadyRained.erase(it);
                }
                rainDay[lake]=i;
            }
        }
        return ans;
    }
};