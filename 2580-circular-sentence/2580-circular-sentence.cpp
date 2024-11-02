class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> v;
        stringstream ss(sentence);
        string t;
        while(getline(ss,t,' '))
        {
            v.push_back(t);
        }
        int n=v.size();
        for(int i=0;i<n-1;i++)
        {
            string curr=v[i];
            string next=v[i+1];
            if(curr[curr.size()-1]!=next[0])
            {
                return false;
            }
        }
        if(v[0][0]!=v[n-1][v[n-1].size()-1]){
            return false;
        }
        return true;
    }
};