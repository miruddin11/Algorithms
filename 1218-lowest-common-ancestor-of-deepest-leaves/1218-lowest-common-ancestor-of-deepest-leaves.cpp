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
    int dfs(TreeNode* root,int &mxDepth,TreeNode*& ans,int depth)
    {
        if(root==NULL){
            return depth-1;
        }
        int l=dfs(root->left,mxDepth,ans,depth+1);
        int r=dfs(root->right,mxDepth,ans,depth+1);
        int d=max(l,r);
        mxDepth=max(mxDepth,d);
        if(l==r&&l==mxDepth){
            ans=root;
        }
        return d;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mxDepth=-1;
        TreeNode* ans=NULL;
        int depth=0;
        dfs(root,mxDepth,ans,depth);
        return ans;
    }
};