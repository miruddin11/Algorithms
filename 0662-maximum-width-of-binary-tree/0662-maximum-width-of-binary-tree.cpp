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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        ll maxW=0;
        q.push({root,0});
        while(!q.empty())
        {
            ll w=q.back().second-q.front().second+1;
            maxW=max(maxW,w);
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front().first;
                ll idx=q.front().second;
                q.pop();
                if(node->left!=NULL){
                    q.push({node->left,2*idx+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,2*idx+2});
                }
            }
        }
        return maxW;
    }
};