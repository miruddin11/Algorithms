class Solution {
public:
    unordered_map<string,multiset<string>> adj;
    vector<string> ans;
    void solve(string fromCity){
        auto& nbrs=adj[fromCity];
        while(!nbrs.empty()){
            string toCity=*nbrs.begin();
            nbrs.erase(nbrs.begin());
            solve(toCity);
        }
        ans.push_back(fromCity);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &t:tickets){
            string from=t[0],to=t[1];
            adj[from].insert(to);
        }
        solve("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};