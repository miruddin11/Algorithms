class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        unordered_set<string> st(folder.begin(),folder.end());
        for(auto &s:folder)
        {
            int n=s.size();
            bool isSubfolder=false;
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='/'){
                    if(st.find(s.substr(0,i))!=st.end()){
                        isSubfolder=true;
                        break;
                    }
                }
            }
            if(!isSubfolder){
                ans.push_back(s);
            }
        }
        return ans;
    }
};