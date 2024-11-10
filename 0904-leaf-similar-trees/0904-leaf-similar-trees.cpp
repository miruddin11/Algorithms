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
    void solve(TreeNode* root,vector<int> &leaf)
    {
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            leaf.push_back(root->val);
            return;
        }
        solve(root->left,leaf);
        solve(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        solve(root1,a);
        vector<int> b;
        solve(root2,b);
        if(a.size()!=b.size()){
            return false;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};