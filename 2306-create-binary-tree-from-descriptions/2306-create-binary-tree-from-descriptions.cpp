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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> isChild;
        for(auto &vec:descriptions)
        {
            int parent=vec[0];
            int child=vec[1];
            int isLeft=vec[2];
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(isLeft==1) mp[parent]->left=mp[child];
            else mp[parent]->right=mp[child];
            isChild.insert(child);
        }
        for(auto &vec:descriptions){
            int parent=vec[0];
            if(isChild.find(parent)==isChild.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};