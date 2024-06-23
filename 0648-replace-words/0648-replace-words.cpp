class Solution {
public:
    string find(string word,unordered_set<string> &st)
    {
        for(int i=0;i<word.size();i++){
            if(st.find(word.substr(0,i))!=st.end()){
                return word.substr(0,i);
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        unordered_set<string> st(dictionary.begin(),dictionary.end());

        string word,ans;
        while(getline(ss,word,' '))
        {
            ans+=find(word,st)+" ";
        }
        ans.pop_back();
        return ans;
    }
};