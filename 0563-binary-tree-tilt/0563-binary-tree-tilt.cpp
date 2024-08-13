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
    int solve(TreeNode *root)
    {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            int x=root->val;
            root->val=0;
            return x;
        }
        int leftSum=solve(root->left);
        int rightSum=solve(root->right);
        int temp=root->val;
        root->val=abs(leftSum-rightSum);

        return temp+leftSum+rightSum;
    }
    int sum(TreeNode* root)
    {
        if(root==NULL){
            return 0;
        }
        return root->val+sum(root->left)+sum(root->right);
    }
    int findTilt(TreeNode* root) {
        solve(root);

        return sum(root);
    }
};