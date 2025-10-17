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
    typedef long long ll;
    void solve(TreeNode* root,ll &currSum){
        if(root==nullptr){
            return;
        }
        solve(root->right,currSum);
        root->val+=currSum;
        currSum=root->val;
        solve(root->left,currSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        ll currSum=0;
        solve(root,currSum);
        return root;
    }
};