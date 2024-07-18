/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode *root,TreeNode *prev,unordered_map<TreeNode*,vector<TreeNode*>> &adj,unordered_set<TreeNode*> &lf)
    {
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            lf.insert(root);
        }
        if(prev!=NULL){
            TreeNode* u=root;
            TreeNode* v=prev;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        makeGraph(root->left,root,adj,lf);
        makeGraph(root->right,root,adj,lf);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_set<TreeNode*> lf;
        unordered_map<TreeNode*,vector<TreeNode*>> adj;
        makeGraph(root,NULL,adj,lf);

        int ans=0;
        for(auto &leaf:lf)
        {
            unordered_set<TreeNode*> visited;
            visited.insert(leaf);
            queue<TreeNode*> q;
            q.push(leaf);
            int level=0;
            while(!q.empty()&&level<=distance)
            {
                int size=q.size();
                while(size--)
                {
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr!=leaf&&lf.find(curr)!=lf.end()){
                        ans+=1;
                    }
                    for(auto nbr:adj[curr]){
                        if(visited.find(nbr)==visited.end()){
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
                level++;
            }
        }
        return ans/2;
    }
};