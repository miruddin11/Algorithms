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
    TreeNode* solve(int &idx,int mx,vector<int> &preorder)
    {
        if(idx>=preorder.size()||preorder[idx]>mx) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=solve(idx,root->val,preorder);
        root->right=solve(idx,mx,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(idx,INT_MAX,preorder);
    }
};