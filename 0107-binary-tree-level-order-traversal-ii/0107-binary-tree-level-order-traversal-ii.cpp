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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> l;
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                l.push_back(node->val);
                if(node->left!=NULL)
                {
                    q.push(node->left);   
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(l);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};