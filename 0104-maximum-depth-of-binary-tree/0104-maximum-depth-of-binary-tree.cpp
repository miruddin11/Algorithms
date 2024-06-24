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
    int mxdepth;
    void solve(TreeNode *root,int h)
    {
        if(root==NULL){
            mxdepth=max(mxdepth,h);
            return; 
        }
        solve(root->left,h+1);
        solve(root->right,h+1);
    }
    int maxDepth(TreeNode* root) {
        mxdepth=INT_MIN;
        solve(root,0);
        return mxdepth;
    }
};