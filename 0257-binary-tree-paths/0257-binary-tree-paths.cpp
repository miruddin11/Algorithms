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
    vector<string> ans;
    void solve(TreeNode* root,string temp)
    {
        if(root==NULL){
            return;
        }
        temp+=to_string(root->val);
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(temp);
            return;
        }
        temp+="->";
        solve(root->left,temp);
        solve(root->right,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string temp="";
        solve(root,temp);
        return ans;
    }
};