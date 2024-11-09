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
    int findBottomLeftValue(TreeNode* root) {
        int ans=root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                ans=node->val;
                if(node->right!=NULL){
                    q.push(node->right);
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
};