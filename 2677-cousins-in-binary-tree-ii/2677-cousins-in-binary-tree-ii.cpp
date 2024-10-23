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
        vector<int> lSum;
        while(!q.empty())
        {
            int sum=0;
            int size=q.size();
            while(size--)
            {
                TreeNode *curr=q.front();
                sum+=curr->val;
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            lSum.push_back(sum);
        }
        q.push(root);
        root->val=0;
        int l=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode *curr=q.front();
                q.pop();
                int siblingSum= curr->left!=NULL?curr->left->val:0;
                siblingSum+= curr->right!=NULL?curr->right->val:0;
                if(curr->left!=NULL)
                {
                    curr->left->val=lSum[l]-siblingSum;
                    q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                    curr->right->val=lSum[l]-siblingSum;
                    q.push(curr->right);
                }
            }
            l++;
        }       
        return root;
    }
};