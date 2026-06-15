struct Node {
    int index;
    string word;
    Node(int index, string &word) : word(word), index(index) {}
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> bucket[26];
        for(auto &word : words) {
            bucket[word[0] - 'a'].emplace_back(0, word);
        }
        int cnt = 0;
        for(auto &ch : s) {
            vector<Node> vec = bucket[ch - 'a'];
            bucket[ch - 'a'].clear();
            for(auto &x : vec) {
                x.index += 1;
                if(x.index == x.word.size()) {
                    cnt += 1;
                } else {
                    bucket[x.word[x.index] - 'a'].emplace_back(x);
                }
            }
        }
        return cnt;
    }
};