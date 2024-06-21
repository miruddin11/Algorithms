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
    int maxSum;
    int solve(TreeNode *root)
    {
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);

        int niche_hi_milgaya_ans= l + r + root->val;// (1)
        int koi_ek_accha= max(l,r) + root->val;// (2)
        int only_root_accha= root->val;// (3)

        maxSum=max({ maxSum, niche_hi_milgaya_ans, koi_ek_accha, only_root_accha });

        return max( koi_ek_accha, only_root_accha );
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};