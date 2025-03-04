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
    bool isEqual(TreeNode *a,TreeNode *b)
    {
        if(!a&&!b) return true;
        if(!a||!b) return false;
        if(a->val!=b->val) return false;
        return isEqual(a->left,b->left)&&isEqual(a->right,b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false; 
        if(root->val==subRoot->val){
            if(isEqual(root,subRoot)){
                return true;
            }
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};