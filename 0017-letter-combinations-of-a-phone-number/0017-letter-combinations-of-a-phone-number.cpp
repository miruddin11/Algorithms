class Solution {
public:
    unordered_map<int,string> digitWordMap;
    vector<string> ans;
    int n;
    void solve(int idx,string &temp,string digits){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        if(digits[idx]=='0'||digits[idx]=='1'){
            solve(idx+1,temp,digits);
            return;
        }
        for(int i=0;i<digitWordMap[digits[idx]-'0'].size();i++){
            temp.push_back(digitWordMap[digits[idx]-'0'][i]);
            solve(idx+1,temp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(n==0){
            return {};
        }
        ans.clear();
        digitWordMap={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        string temp;
        solve(0,temp,digits);
        return ans;
    }
};