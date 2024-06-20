/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p||root==q){
            return root;
        }
        TreeNode* LeftN= lowestCommonAncestor(root->left ,p,q);
        TreeNode* RightN=lowestCommonAncestor(root->right,p,q);
        if(LeftN!=NULL && RightN!=NULL)
        {
            return root;
        }
        if(RightN!=NULL)
        {
            return RightN;
        }

        return LeftN;
    }
};