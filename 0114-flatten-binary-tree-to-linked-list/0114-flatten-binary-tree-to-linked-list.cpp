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
    TreeNode* prev;
    void solve(TreeNode *root)
    {
        if(root==NULL){
            return;
        }
        if(prev!=NULL){
            prev->right=root;
            prev->left=NULL;
        }
        prev=root;
        TreeNode* r=root->right;
        solve(root->left);
        solve(r);
    }
    void flatten(TreeNode* root) {
        prev=NULL;
        solve(root);
    }
};