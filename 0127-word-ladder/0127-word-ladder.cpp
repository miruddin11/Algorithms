class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto &s:wordList) st.insert(s);
        if(st.find(endWord)==st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int level=0;
        while(!q.empty())
        {
            level+=1;
            int size=q.size();
            while(size--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string temp=curr;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(curr==temp) continue;
                        if(temp==endWord) return level+1;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};