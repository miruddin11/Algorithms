class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(int index,string newString,string oldString,int n,
    unordered_map<string,vector<string>> &mp)
    {
        if(n==1){
            return true;
        }
        if(index==n-1){
            if(dp.find(newString)!=dp.end()){
                return dp[newString];
            }
            else{
                return dp[newString]=solve(0,"",newString,n-1,mp);
            }
        }
        string temp=oldString.substr(index,2);
        if(mp.find(temp)==mp.end()){
            return false;
        }
        for(auto &str:mp[temp]){
            if(solve(index+1,newString+str,oldString,n,mp)){
                return true;
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        dp.clear();
        unordered_map<string,vector<string>> mp;
        int n=bottom.size();
        for(auto str:allowed){
            mp[str.substr(0,2)].push_back(str.substr(2));
        }
        return solve(0,"",bottom,n,mp);
    }
};