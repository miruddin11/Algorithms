class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        vector<char> vowel;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
            {
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(),vowel.end());
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
            {
                s[i]=vowel[k++];
            }
        }
        return s;
    }
};