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
    unordered_map<TreeNode*,TreeNode*> par;
    int t;
    TreeNode *target;
    void solve(TreeNode* root)
    {
        if(!root) return;
        if(root->val==t){
            target=root;
        }
        if(root->left) par[root->left]=root;
        solve(root->left);
        if(root->right) par[root->right]=root;
        solve(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        t=start;
        target=NULL;
        solve(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left&&vis.count(curr->left)==0){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right&&vis.count(curr->right)==0){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(par.find(curr)!=par.end()&&vis.count(par[curr])==0)
                {
                    q.push(par[curr]);
                    vis.insert(par[curr]);
                }
            }
            level++;
        }
        return level-1;
    }
};