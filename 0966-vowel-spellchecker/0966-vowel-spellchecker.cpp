class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet;
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;
        for(auto &word:wordlist){
            exactSet.insert(word);
            string lowerString=word;
            transform(lowerString.begin(),lowerString.end(),lowerString.begin(),::tolower);
            if(caseMap.find(lowerString)==caseMap.end()){
                caseMap[lowerString]=word;
            }
            for(int i=0;i<lowerString.size();i++){
                char ch=lowerString[i];
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    lowerString[i]='*';
                }
            }
            if(vowelMap.find(lowerString)==vowelMap.end()){
                vowelMap[lowerString]=word;
            }
        }
        vector<string> ans;
        for(auto &query:queries){
            //exact match
            string lowerString=query;
            transform(lowerString.begin(),lowerString.end(),lowerString.begin(),::tolower);
            if(exactSet.find(query)!=exactSet.end()){
                ans.push_back(query);
            }
            //case mis match
            else if(caseMap.find(lowerString)!=caseMap.end()){
                ans.push_back(caseMap[lowerString]);
            }
            else{
                for(int i=0;i<lowerString.size();i++){
                    char ch=lowerString[i];
                    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                        lowerString[i]='*';
                    }
                }
                //vowel mis match
                if(vowelMap.find(lowerString)!=vowelMap.end()){
                    ans.push_back(vowelMap[lowerString]);
                }
                //no match at all
                else{
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};