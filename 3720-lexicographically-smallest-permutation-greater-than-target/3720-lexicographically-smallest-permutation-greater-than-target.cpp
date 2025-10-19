class Solution {
public:
    int n;
    int solve(vector<char> &temp,vector<int> &freq,string &target,int flag,string &ans){
        if(!ans.empty()){
            return 1;
        }
        if(temp.size()==n){
            if(flag==1){
                ans=string(temp.begin(),temp.end());
                return true;
            }
            return false;
        }
        int lastIdx=temp.size();
        for(int j=0;j<26;j++){
            if(freq[j]==0) continue;
            char ch=(char)(j+'a');
            if(flag==0&&ch<target[lastIdx]) continue;
            temp.push_back(ch);
            freq[j]-=1;
            if(ch>target[lastIdx]){
                flag=1;
            }
            if(solve(temp,freq,target,flag,ans)){
                return true;
            }
            freq[j]+=1;
            temp.pop_back();
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        n=target.size();
        vector<int> freq(26,0);
        for(char ch:s) freq[ch-'a']+=1;
        vector<char> temp;
        string ans;
        solve(temp,freq,target,0,ans);
        return ans;
    }
};