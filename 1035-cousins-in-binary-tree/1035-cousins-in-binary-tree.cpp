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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});
        while(!q.empty())
        {
            int size=q.size();
            bool x_found=false;
            int x_par;
            int y_par;
            bool y_found=false;
            while(size--)
            {
                TreeNode* node=q.front().first;
                int par=q.front().second;
                q.pop();
                if(node->val==x){
                    x_found=true;
                    x_par=par;
                }
                if(node->val==y){
                    y_found=true;
                    y_par=par;
                }
                if(node->left!=NULL){
                    q.push({node->left,node->val});
                }
                if(node->right!=NULL){
                    q.push({node->right,node->val});
                }
            }
            if(x_found&&y_found&&x_par!=y_par){
                return true;
            }
        }
        return false;
    }
};