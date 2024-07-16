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
        string rootToS="";
        findPath(root,startValue,rootToS);
        string rootToD="";
        findPath(root,destValue,rootToD);
        //To find the Common Path
        int i=0,j=0;
        while(i<rootToS.size()&&j<rootToD.size()&&rootToS[i]==rootToD[j])
        {
            i++; j++;
        }
        string ans;
        while(i<rootToS.size()){
            ans.push_back('U');
            i++;
        }
        while(j<rootToD.size()){
            ans.push_back(rootToD[j]);
            j++;
        }
        return ans;
    }
};