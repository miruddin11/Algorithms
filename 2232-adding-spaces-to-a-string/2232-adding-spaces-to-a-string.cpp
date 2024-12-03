class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int n=spaces.size();
        int prev=0;
        for(int i=0;i<n;i++)
        { 
            ans+=s.substr(prev,spaces[i]-prev);
            ans+=" ";
            prev=spaces[i];
        }
        ans+=s.substr(prev);
        return ans;
    }
};