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
    void inOrder(TreeNode *root,vector<int> &a)
    {
        if(!root){
            return;
        }
        inOrder(root->left,a);
        a.push_back(root->val);
        inOrder(root->right,a);
    }
    TreeNode* ConstructBST(int l,int r,vector<int> &a)
    {
        if(l>r) return NULL;
        int mid=l+ (r-l)/2;

        TreeNode* root=new TreeNode(a[mid]);
        root->left=ConstructBST(l,mid-1,a);
        root->right=ConstructBST(mid+1,r,a);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        inOrder(root,a);
        int l=0;
        int r=a.size()-1;
        return ConstructBST(l,r,a);
    }
};