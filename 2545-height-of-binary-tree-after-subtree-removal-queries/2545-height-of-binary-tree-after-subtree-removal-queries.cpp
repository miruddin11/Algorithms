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
#define N 100001
class Solution {
public:
    int level[N];
    int height[N];
    int maxHt[N];
    int secondmaxHt[N];
    int findHt(TreeNode *root,int l)
    {
        if(root==nullptr){
            return 0;
        }
        level[root->val]=l;
        height[root->val]=max(findHt(root->right,l+1),findHt(root->left,l+1))+1;
        if(maxHt[l]<height[root->val]){
            secondmaxHt[l]=maxHt[l];
            maxHt[l]=height[root->val];
        }
        else if(secondmaxHt[l]<height[root->val])
        {
            secondmaxHt[l]=height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHt(root,0);
        vector<int> ans;
        for(auto &q:queries)
        {
            int L=level[q];
            int ht=L+ (maxHt[L]==height[q]? secondmaxHt[L]:maxHt[L]) -1;
            ans.push_back(ht);
        }
        return ans;
    }
};