class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string a,string b)
    {
        if(a.compare(b)==0) return true;
        if(a.size()<=1) return false;
        int n=a.size();
        bool flag=false;
        string key=a+" "+b;
        if(mp.count(key)>0){
            return mp[key];
        }
        for(int i=1;i<=n-1;i++)
        {
            bool c1=solve(a.substr(0,i),b.substr(n-i,i))&&solve(a.substr(i,n-i),b.substr(0,n-i));
            bool c2=solve(a.substr(0,i),b.substr(0,i))&&solve(a.substr(i,n-i),b.substr(i,n-i));
            if(c1||c2){
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n==0&&m==0) return true;
        if(m!=n) return false;
        mp.clear();
        return solve(s1,s2);
    }
};