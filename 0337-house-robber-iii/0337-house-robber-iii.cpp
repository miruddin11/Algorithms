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
    pair<int,int> solve(TreeNode* root)
    {
        if(!root) return {0,0};
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        //with Root
        int rootTaken=root->val+left.second+right.second;
        //without root
        int children=max(left.first,left.second)+max(right.first,right.second);

        return {rootTaken,children};
    }
    int rob(TreeNode* root) {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};