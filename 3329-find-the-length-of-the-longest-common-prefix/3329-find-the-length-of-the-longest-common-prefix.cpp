class TrieNode{
    public:
    TrieNode* children[10];
};
class Solution {
public:
    TrieNode* getTrieNode(){
        TrieNode *node=new TrieNode();
        for(int i=0;i<10;i++){
            node->children[i]=NULL;
        }
        return node;
    }
    void insert(TrieNode *root,int num)
    {
        TrieNode* crawl=root;
        string str=to_string(num);
        for(auto ch:str){
            int idx=ch-'0';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=getTrieNode();
            }
            crawl=crawl->children[idx];
        }
    }
    int search(TrieNode *root,int num)
    {
        TrieNode* crawl=root;
        string str=to_string(num);
        int len=0;
        for(auto ch:str){
            int idx=ch-'0';
            if(crawl->children[idx]!=NULL){
                len++;
                crawl=crawl->children[idx];
            }else{
                break;
            }
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *root=getTrieNode();
        for(auto &num:arr1){
            insert(root,num);
        }
        int ans=0;
        for(auto &num:arr2){
            ans=max(ans,search(root,num));
        }
        return ans;
    }
};