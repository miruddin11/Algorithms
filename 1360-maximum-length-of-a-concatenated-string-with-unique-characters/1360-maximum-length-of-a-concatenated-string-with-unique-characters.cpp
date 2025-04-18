class Solution {
public:
    bool isDuplicate(string &s1,string &s2)
    {
        vector<int> f(26,0);
        for(auto &ch:s1)
        {
            if(f[ch-'a']>0){
                return true;
            }
            f[ch-'a']+=1;
        }
        for(auto &ch:s2)
        {
            if(f[ch-'a']>0){
                return true;
            }
        }
        return false;
    }
    int solve(int idx,string temp,int n,vector<string> &arr)
    {
        if(idx==n){
            return temp.size();
        }
        int include=0;
        int exclude=0;
        if(isDuplicate(arr[idx],temp))
        {
            exclude=solve(idx+1,temp,n,arr);
        }
        else{
            exclude=solve(idx+1,temp,n,arr);
            include=solve(idx+1,temp+arr[idx],n,arr);
        }
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();
        return solve(0,temp,n,arr);
    }
};