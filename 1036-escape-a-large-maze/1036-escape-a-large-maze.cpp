class Solution {
public:
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
    int limit=(int)2*1e4;
    string getKey(int x,int y){
        return to_string(x)+"-"+to_string(y);
    }
    bool solve(vector<int> &source,vector<int> &target,unordered_set<string> &blockedSet){
        queue<pair<int,int>> q;
        unordered_set<string> visited;
        q.push({source[0],source[1]});
        visited.insert(getKey(source[0],source[1]));
        int tx=target[0],ty=target[1];
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==tx&&y==ty){
                return true;
            }
            if(visited.size()>limit){
                return true;
            }
            for(auto &dir:direction){
                int nx=x+dir[0],ny=y+dir[1];
                if(nx<0||nx>=1e6||ny<0||ny>=1e6) continue;
                string key=getKey(nx,ny);
                if(blockedSet.count(key)>0||visited.count(key)>0) continue;
                visited.insert(key);
                q.push({nx,ny});
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.size()==0){
            return true;
        }
        unordered_set<string> blockedSet;
        for(auto &b:blocked){
            string key=getKey(b[0],b[1]);
            blockedSet.insert(key);
        }
        if(blockedSet.count(getKey(source[0],source[1]))||blockedSet.count(getKey(target[0],target[1]))){
            return false;
        }
        return solve(source,target,blockedSet)&&solve(target,source,blockedSet);
    }
};