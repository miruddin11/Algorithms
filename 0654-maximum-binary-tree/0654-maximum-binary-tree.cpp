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
    TreeNode* build(vector<int> &nums,int start,int end)
    {
        if(start>end) return nullptr;
        int maxIdx=start;
        for(int idx=start+1;idx<=end;idx++){
            if(nums[idx]>nums[maxIdx]){
                maxIdx=idx;
            }
        }
        TreeNode* root=new TreeNode(nums[maxIdx]);
        root->left=build(nums,start,maxIdx-1);
        root->right=build(nums,maxIdx+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return nullptr;
        return build(nums,0,n-1);
    }
};