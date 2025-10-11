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
    int moves;
    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        moves+=abs(l)+abs(r);
        return (l+r+root->val)-1;
    }
    int distributeCoins(TreeNode* root) {
        moves=0;
        solve(root);
        return moves;
    }
};