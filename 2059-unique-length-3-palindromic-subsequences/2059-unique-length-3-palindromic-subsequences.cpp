class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> maxOcc(26,INT_MIN);
        vector<int> minOcc(26,INT_MAX);

        for(int i=0;i<s.length();i++)
        {
            int idx=s[i]-'a';
            minOcc[idx]=min(minOcc[idx],i);
            maxOcc[idx]=max(maxOcc[idx],i);
        }
        int c=0;
        for(int i=0;i<26;i++)
        {
            if((minOcc[i]!=INT_MAX)&&(maxOcc[i]!=INT_MIN))
            {
                unordered_set<char> set;
                for(int j=minOcc[i]+1;j<maxOcc[i];j++)
                {
                    set.insert(s[j]);
                }
                c+=set.size();
            }
        }

        return c;
    }
};