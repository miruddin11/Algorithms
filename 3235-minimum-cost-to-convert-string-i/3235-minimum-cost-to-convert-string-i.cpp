#define ll long long
class Solution {
public:
    void Dijasktra(vector<vector<ll>> &adjMatrix,char source,unordered_map<char,vector<pair<char,int>>> &adj)
    {
        priority_queue<pair<int,char> , vector<pair<int,char>> , greater<pair<int,char>> > pq;// {distance , node}-->min_priority queue
        pq.push({0,source});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            char node=pq.top().second;
            pq.pop();
            for(auto &nbr:adj[node]){
                char adjNode=nbr.first;
                int d=nbr.second;
                if(adjMatrix[source-'a'][adjNode-'a']>d+dis){
                    adjMatrix[source-'a'][adjNode-'a']=d+dis;
                    pq.push({d+dis,adjNode});
                }
            }
        }
        return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> adjMatrix(26,vector<ll>(26,INT_MAX));
        unordered_map<char , vector< pair<char,int> > > adj;
        for(int i=0;i<original.size();i++)
        {
            char u=original[i];
            char v=changed[i];
            int w=cost[i];
            adj[u].push_back({v,w});
        }
        for(int i=0;i<original.size();i++)
        {
            Dijasktra(adjMatrix,original[i],adj);
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(adjMatrix[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }
            ans+=adjMatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};