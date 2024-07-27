#define ll long long
class Solution {
public:
    void floyd_Warshal(vector<vector<ll>> &adjMatrix, vector<char>& original, vector<char>& changed,vector<int>& cost){
        for(int i=0;i<changed.size();i++)
        {
            int s=original[i]-'a';
            int t=changed[i]-'a';
            adjMatrix[s][t]=min(adjMatrix[s][t],(ll) cost[i]);
        }

        //Floyd Warshall
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<ll>> adjMatrix(26,vector<ll>(26,INT_MAX));
        floyd_Warshal(adjMatrix,original,changed,cost);

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