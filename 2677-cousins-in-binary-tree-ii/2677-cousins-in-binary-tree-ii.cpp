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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lSum=root->val;
        while(!q.empty())
        {
            int size=q.size();
            int nextLSum=0;
            while(size--)
            {
                TreeNode *curr=q.front();
                q.pop();
                curr->val=lSum-curr->val;
                int siblingSum= curr->left!=NULL?curr->left->val:0;
                siblingSum+= curr->right!=NULL?curr->right->val:0;
                if(curr->left!=NULL)
                {
                    nextLSum+=curr->left->val;
                    curr->left->val=siblingSum;
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    nextLSum+=curr->right->val;
                    curr->right->val=siblingSum;
                    q.push(curr->right);
                }
            }
            lSum=nextLSum;
        }       
        return root;
    }
};