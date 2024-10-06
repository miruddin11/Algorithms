class Solution {
public:
    void stringToWord(string s,vector<string> &v)
    {
        stringstream ss(s);
        string t;
        while(getline(ss,t,' ')){
            v.push_back(t);
        }
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()<sentence2.size()){
            swap(sentence1,sentence2);
        }
        vector<string> v1;
        stringToWord(sentence1,v1);
        vector<string> v2;
        stringToWord(sentence2,v2);
        int i=0,j=v1.size()-1;
        int k=0,l=v2.size()-1;
        while(k<v2.size()&&i<v1.size()&&v2[k]==v1[i])
        {
            i++;
            k++;
        }
        while(l>=k&&v2[l]==v1[j]){
            l--;
            j--;
        }
        return l<k;
    }
};