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
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        // Taking root
        int rootTaken=root->val;
        //Left grand children
        if(root->left){
            rootTaken+=rob(root->left->left);
            rootTaken+=rob(root->left->right);
        }
        //Right grand children
        if(root->right){
            rootTaken+=rob(root->right->left);
            rootTaken+=rob(root->right->right);
        }

        //Without root
        int childSum=rob(root->right)+rob(root->left);
        return mp[root]=max(rootTaken,childSum);
    }
};