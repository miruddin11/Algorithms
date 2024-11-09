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
    int solve(TreeNode* root,int mx)
    {
        if(root==NULL){
            return 0;
        }
        int ans=(root->val>=mx)?1:0;
        mx=max(mx,root->val);
        int l=solve(root->left,mx);
        int r=solve(root->right,mx);
        return l+r+ans;
    }
    int goodNodes(TreeNode* root) {
        int mx=INT_MIN;
        return solve(root,mx);
    }
};