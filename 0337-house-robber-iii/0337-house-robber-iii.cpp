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
    vector<int> solve(TreeNode* root)
    {
        if(!root) return {0,0};
        vector<int> left=solve(root->left);
        vector<int> right=solve(root->right);
        //with Root
        int rootTaken=root->val+left[1]+right[1];
        //without root
        int children=max(left[0],left[1])+max(right[0],right[1]);

        return {rootTaken,children};
    }
    int rob(TreeNode* root) {
        vector<int> ans=solve(root);
        return max(ans[0],ans[1]);
    }
};