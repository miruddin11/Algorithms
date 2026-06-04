class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token = "";
        vector<string> st;
        while(getline(ss, token, '/')) {
            if(token == "." || token == ""){
                continue;
            }
            if(token != "..") {
                st.push_back(token);
            } else if(!st.empty()) {
                st.pop_back();
            }
        }
        string ans = "";
        for(auto &dir : st) {
            ans += "/" + dir;
        }
        return ans.empty() ? "/" : ans;
    }
};