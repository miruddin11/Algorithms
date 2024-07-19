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
    int goodPair;
    vector<int> solve(TreeNode* root,int distance){
        if(root==NULL){
            return {0};
        }
        if(root->left==NULL&& root->right==NULL){
            return {1};
        }
        vector<int> l=solve(root->left,distance);
        vector<int> r=solve(root->right,distance);
        for(auto &x:l){
            for(auto &y:r){
                if(x!=0&&y!=0&&x+y<=distance){
                    goodPair++;
                }
            }
        }
        vector<int> merged;
        for(auto &x:l){
            if(x!=0&&x+1<=distance)
            merged.push_back(x+1);
        }
        for(auto &y:r){
            if(y!=0&&y+1<=distance)
            merged.push_back(y+1);
        }
        return merged;
    }
    int countPairs(TreeNode* root, int distance) {
        ios::sync_with_stdio(false); cin.tie(0);
        goodPair=0;
        solve(root,distance);
        return goodPair;
    }
};