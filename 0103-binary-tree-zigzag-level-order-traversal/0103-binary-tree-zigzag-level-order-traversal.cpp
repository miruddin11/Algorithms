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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int l=0;
        while(!dq.empty())
        {
            int size=dq.size();
            vector<int> level;
            while(size--)
            {
                if(l%2==0){
                    TreeNode *curr=dq.back();
                    dq.pop_back();
                    level.push_back(curr->val);
                    if(curr->left!=NULL){
                        dq.push_front(curr->left);
                    }
                    if(curr->right!=NULL){
                        dq.push_front(curr->right);
                    }
                }
                else{
                    TreeNode *curr=dq.front();
                    dq.pop_front();
                    level.push_back(curr->val);
                    if(curr->right!=NULL){
                        dq.push_back(curr->right);
                    }
                    if(curr->left!=NULL){
                        dq.push_back(curr->left);
                    }
                }
            }
            ans.push_back(level);
            l++;
        }
        return ans;
    }
};