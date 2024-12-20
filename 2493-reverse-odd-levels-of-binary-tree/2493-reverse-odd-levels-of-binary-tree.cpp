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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            vector<TreeNode*> l;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                l.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2==1)
            {
                int left=0,right=l.size()-1;
                while(left<=right)
                {
                    swap(l[left]->val,l[right]->val);
                    left+=1;
                    right-=1;
                }
            }
            level+=1;
        }
        return root;
    }
};