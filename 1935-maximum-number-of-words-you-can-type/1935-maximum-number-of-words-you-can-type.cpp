class Solution {
public:
    int brokenCount(char ch,vector<string> &words){
        int broken=0;
        for(int i=0;i<words.size();i++){
            if(words[i].compare("*")==0){
                continue;
            }
            string word=words[i];
            for(auto &c:word){
                if(c==ch){
                    broken+=1;
                    words[i]="*";
                    break;
                }
            }
        }
        return broken;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        int count=0;
        vector<string> words;
        stringstream ss(text);
        string word;
        while(getline(ss,word,' ')){
            words.push_back(word);
        }
        for(auto &ch:brokenLetters)
        {
            count+=brokenCount(ch,words);
        }
        return words.size()-count;
    }
};