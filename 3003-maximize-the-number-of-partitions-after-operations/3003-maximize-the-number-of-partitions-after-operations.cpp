class Solution {
public:
    unordered_map<long long,int> mp;
    int solve(int i,long long uniqueChars,bool canChange,string &s,int k){
        if(i>=s.size()){
            return 0;
        }
        long long key=(i<<27)|(uniqueChars<<1)|canChange;
        if(mp.count(key)){
            return mp[key];
        }
        int charIdx=s[i]-'a';
        long long newUniqueChars=uniqueChars|(1LL<<charIdx);
        int uniqueCharCnt=__builtin_popcountll(newUniqueChars);
        int ans=0;
        if(uniqueCharCnt>k){
            ans=1+solve(i+1,(1LL<<charIdx),canChange,s,k);
        }
        else{
            ans=solve(i+1,newUniqueChars,canChange,s,k);
        }
        if(canChange){
            for(int newCharIdx=0;newCharIdx<26;newCharIdx++){
                long long newCharSet=uniqueChars|(1LL<<newCharIdx);
                int newCharCnt=__builtin_popcountll(newCharSet);
                if(newCharCnt>k){
                    ans=max(ans,1+solve(i+1,(1LL<<newCharIdx),false,s,k));
                }
                else{
                    ans=max(ans,solve(i+1,newCharSet,false,s,k));
                }
            }
        }
        return mp[key]=ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(0,0,true,s,k)+1;
    }
};