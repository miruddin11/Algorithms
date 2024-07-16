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
    TreeNode* LowestCommonAncestor(TreeNode *root,int p,int q)
    {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p||root->val==q){
            return root;
        }
        TreeNode* LeftN=LowestCommonAncestor(root->left,p,q);
        TreeNode* RightN=LowestCommonAncestor(root->right,p,q);
        if(LeftN!=NULL && RightN!=NULL){
            return root;
        }
        if(RightN!=NULL) return RightN;
        return LeftN;
    }
    bool findPath(TreeNode *root,int target,string &path)
    {
        if(root==NULL){
            return false;
        }
        if(root->val==target)
        {
            return true;
        }
        path.push_back('L');
        if(findPath(root->left,target,path)==true){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right,target,path)==true){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA=LowestCommonAncestor(root,startValue,destValue);

        string lcaToS="";
        findPath(LCA,startValue,lcaToS);
        string lcaToD="";
        findPath(LCA,destValue,lcaToD);

        string ans;
        for(int i=0;i<lcaToS.size();i++) ans.push_back('U');
        ans+=lcaToD;
        return ans;
    }
};