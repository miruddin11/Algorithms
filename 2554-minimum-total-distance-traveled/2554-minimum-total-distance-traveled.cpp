#define MAX 10000000000000LL
class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> dp;
    ll mincost(vector<int>& robot,int robo_pos, vector<int>& factories,int fact_pos){
        if(robo_pos<0)  return 0;
        if(fact_pos<0)  return MAX;
        if(dp[robo_pos][fact_pos]!=-1)
        {
            return dp[robo_pos][fact_pos];
        }
        ll include=abs(robot[robo_pos]-factories[fact_pos])+mincost(robot,robo_pos-1,factories,fact_pos-1);
        ll exclude=mincost(robot,robo_pos,factories,fact_pos-1);
        return dp[robo_pos][fact_pos]=min(include,exclude);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> factories;
        for(auto &v:factory)
        {
            int pos=v[0];
            int count=v[1];
            for(int j=0;j<count;j++)
            {
                factories.push_back(pos);
            }
        }
        dp.resize(robot.size(),vector<ll>(factories.size(),-1));
        return mincost(robot,robot.size()-1,factories,factories.size()-1);
    }
};