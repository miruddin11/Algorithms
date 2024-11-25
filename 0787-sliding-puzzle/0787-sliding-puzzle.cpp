class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> adj={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string b;
        for(auto &row:board)
        {
            for(auto &c:row)
            {
                b+=to_string(c);
            }
        }
        queue<tuple<int,string,int>> q;
        q.push({b.find('0'),b,0});
        unordered_set<string> visit;
        visit.insert(b);
        string target="123450";
        while(!q.empty())
        {
            auto [i,b,length]=q.front();
            q.pop();
            if (b==target) {
                return length;
            }
            for (auto &j:adj[i]) 
            {
                string new_b=b;
                swap(new_b[i],new_b[j]);
                if(visit.find(new_b)==visit.end()) {
                    q.push({j,new_b,length+1});
                    visit.insert(new_b);
                }
            }
        }
        return -1;
    }
};