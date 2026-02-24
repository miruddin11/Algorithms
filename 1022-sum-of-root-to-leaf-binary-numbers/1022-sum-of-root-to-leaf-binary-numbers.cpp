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
    vector<string> values;
    void solve(TreeNode* root , string s) {
        if(root == nullptr) {
            return;
        }
        s += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            values.push_back(s);
        }
        solve(root->left , s);
        solve(root->right , s);
    }
    int toBin(string a){
        int bin = 0;
        for(auto &c : a) {
            bin = (bin << 1) + (c - '0');
        }
        return bin;
    }
    int sumRootToLeaf(TreeNode* root) {
        values.clear();
        solve(root , "");
        int ans = 0;
        for(auto &val : values) {
            ans += toBin(val);
        }
        return ans;
    }
};