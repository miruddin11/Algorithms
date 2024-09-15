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
    TreeNode* head;
    TreeNode* prev;
    void solve(TreeNode *root)
    {
        if(root==NULL){
            return;
        }
        if(prev==NULL){
            head=root;
        }else{
            prev->right=root;
            prev->left=NULL;
        }
        TreeNode* r=root->right;
        prev=root;
        solve(root->left);
        solve(r);
    }
    void flatten(TreeNode* root) {
        head=NULL;
        prev=NULL;
        solve(root);
    }
};