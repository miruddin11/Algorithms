class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &q : queries) {
            int u = q[0] , v = q[1];
            int len = 1;
            while(u != v){
                if(u > v) {
                    u = u / 2;
                } else{
                    v = v / 2;
                }
                len += 1;
            } 
            ans.push_back(len);
        }
        return ans;
    }
};