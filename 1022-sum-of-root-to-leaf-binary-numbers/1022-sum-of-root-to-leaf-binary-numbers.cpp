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
    int solve(TreeNode* root , int sum) {
        if(root == nullptr) {
            return 0;
        }
        sum = sum * 2 + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            return sum;
        }
        return solve(root->left , sum) + solve(root->right , sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root , 0);
    }
};