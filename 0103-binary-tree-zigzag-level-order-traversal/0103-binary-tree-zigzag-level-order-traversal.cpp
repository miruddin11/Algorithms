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
        deque<TreeNode*> dq;
        vector<vector<int>> ans;
        dq.push_back(root);
        int level=0;
        while(!dq.empty())
        {
            int size=dq.size();
            vector<int> t;
            while(size--)
            {
                if(level%2==1){
                    TreeNode* node=dq.front();
                    dq.pop_front();
                    t.push_back(node->val);
                    if(node->right!=NULL){
                        dq.push_back(node->right);
                    }
                    if(node->left!=NULL){
                        dq.push_back(node->left);
                    }
                }
                else
                {
                    TreeNode* node=dq.back();
                    dq.pop_back();
                    t.push_back(node->val);
                    if(node->left!=NULL){
                        dq.push_front(node->left);
                    }
                    if(node->right!=NULL){
                        dq.push_front(node->right);
                    }
                }
            }
            level++;
            ans.push_back(t);
        }
        return ans;
    }
};