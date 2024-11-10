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
    int idx;
    TreeNode* solve(vector<int> &pre,vector<int> &in,int start,int end)
    {
        if(start>end) return nullptr;
        TreeNode* root=new TreeNode(pre[idx]);
        int i;
        for(i=0;i<pre.size();i++)
        {
            if(in[i]==pre[idx]){
                break;
            }
        }
        idx++;
        root->left=solve(pre,in,start,i-1);
        root->right=solve(pre,in,i+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx=0;
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};