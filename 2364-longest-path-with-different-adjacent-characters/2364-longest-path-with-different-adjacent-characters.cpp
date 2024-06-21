class Solution {
public:
    int maxlen;
    int solve(int curr, int parent, unordered_map<int,vector<int>> &adj, string &s)
    {
        int longest=0,second_longest=0;
        for(auto child:adj[curr]){
            if( child==parent ) continue;
            int longest_from_child= solve(child, curr, adj, s);
            
            if(s[child]==s[curr]) continue;
            if(longest_from_child>second_longest) second_longest=longest_from_child;
            if(second_longest>longest) swap(second_longest,longest);
        }

        int niche_hi_milgaya_ans= 1+second_longest+longest;
        int koi_ek_accha = 1+ max(second_longest , longest);
        int root_hi_accha= 1;
        maxlen= max({maxlen, niche_hi_milgaya_ans, koi_ek_accha, root_hi_accha});
        return max(root_hi_accha, koi_ek_accha);
    }
    int longestPath(vector<int>& parent, string s) {
        maxlen=0;
        int n=parent.size();
        unordered_map<int,vector<int>> adj;

        for(int i=1;i<n;i++)
        {
            int u=i;
            int v=parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(0,-1,adj,s);
        return maxlen;
    }
};