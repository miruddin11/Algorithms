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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int max_value=INT_MIN;
            int size=q.size();
            while(size--)
            {
                TreeNode *node=q.front();
                q.pop();
                max_value=max(max_value,node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(max_value);
        }
        return ans;
    }
};