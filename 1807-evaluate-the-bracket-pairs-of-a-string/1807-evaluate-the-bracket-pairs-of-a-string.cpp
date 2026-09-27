class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        int n = knowledge.size();
        for(int i = 0 ; i < n; i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                string key;
                i++;
                while(i < s.size() && s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                string value;
                value = mp[key];
                if(value.size() == 0) {
                    value = "?";
                }
                ans += value;
            }
            else ans.push_back(s[i]);
        }
        return ans; 
    }
};