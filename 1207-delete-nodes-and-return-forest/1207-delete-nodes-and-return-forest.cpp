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
    TreeNode* deleteNodes(TreeNode *root, unordered_set<int> &st, vector<TreeNode*> &ans)
    {
        if(root==NULL){
            return NULL;
        }
        root->left=deleteNodes(root->left,st,ans);
        root->right=deleteNodes(root->right,st,ans);
        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL) ans.push_back(root->left);

            if(root->right!=NULL) ans.push_back(root->right);

            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        deleteNodes(root,st,ans);

        if(st.find(root->val)==st.end()){
            ans.push_back(root);
        }
        return ans;
    }
};