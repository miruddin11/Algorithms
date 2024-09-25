class TrieNode{
    public:
    int countP;
    TrieNode* children[26];
};
class Solution {
public:
    TrieNode* getTrieNode()
    {
        TrieNode *node=new TrieNode();
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        node->countP=0;
        return node;
    }
    void insert(TrieNode* root,string s)
    {
        TrieNode *crawl=root;
        for(auto &ch:s){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=getTrieNode();
            }
            crawl->children[idx]->countP+=1;
            crawl=crawl->children[idx];
        }
    }
    int search(TrieNode *root,string s)
    {
        int score=0;
        TrieNode *crawl=root;
        for(auto &ch:s)
        {
            int idx=ch-'a';
            score+=crawl->children[idx]->countP;
            crawl=crawl->children[idx];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *root=getTrieNode();
        for(auto &w:words){
            insert(root,w);
        }
        int n=words.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=search(root,words[i]);
        }
        return ans;
    }
};