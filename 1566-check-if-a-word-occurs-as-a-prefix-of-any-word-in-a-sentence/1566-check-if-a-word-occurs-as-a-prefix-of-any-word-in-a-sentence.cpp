class Solution {
public:
    bool found(string &a,string &b)
    {
        if(a.size()>b.size()) return false;
        int i=0;
        while(i<a.size())
        {
            if(a[i]!=b[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string e;
        int c=1;
        while(getline(ss,e,' '))
        {
            if(found(searchWord,e)) 
            {
                return c;
            }
            c+=1;
        }
        return -1;
    }
};