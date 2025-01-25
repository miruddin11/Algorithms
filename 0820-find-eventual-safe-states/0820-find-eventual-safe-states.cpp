class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        queue<int> que;
	    vector<int> indegree(V, 0);
	    int count = 0;
	    for(int u = 0; u < V; u++) {
	        for(int &v : graph[u]) {
                adj[v].push_back(u);
	            indegree[u]++;
	        }
	    }
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
        vector<bool> safe(V, false);
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
            safe[u] = true;
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	            
	        }
	    }
	    vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};